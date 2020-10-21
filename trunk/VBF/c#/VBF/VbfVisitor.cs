using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Antlr4.Runtime.Misc;
using Antlr4.Runtime.Tree;
using Antlr4.Runtime;
using System.Globalization;

namespace VBF
{    /// <summary>
     /// The class is used to describe the Vbf visitor.
     /// </summary>
     public class VbfVisitor : VbfBaseVisitor<object>
    {
        /// <summary>
        /// The database of instance which will be loaded from the VBF file.
        /// </summary>
        protected Database database = new Database();

        /// <summary>
        /// Gets the loaded database instance.
        /// </summary>
        public Database Database
        {
            get
            {
                return database;
            }
        }

        /// <summary>
        /// The Antlr framework calls the method to notify Parser Rule in g4 file(database) was been found.
        /// </summary>
        /// <param name="context"></param>
        /// <returns></returns>
        public override object VisitDatabase([NotNull] VbfParser.DatabaseContext context)
        {
            //Exception is not null means some errors happen and vbf file is invalid.
            if (context.exception != null)
            {
                Console.WriteLine(context.exception);
                //database.Valid = false;
                return base.VisitDatabase(context);
            }

            return base.VisitDatabase(context);
        }

        /// <summary>
        /// The Antlr framework calls the method to notify Parser Rule in g4 file(versionSection) was been found.
        /// </summary>
        /// <param name="context"></param>
        /// <returns></returns>
        public override object VisitVersionSection([NotNull] VbfParser.VersionSectionContext context)
        {
            //Exception is not null means some errors happen and vbf file is invalid.
            if (context.exception != null)
            {
                Console.WriteLine(context.exception);
                database.VersionIsValidVaule = ValidityOfContent.ParseError;
                return base.VisitVersionSection(context);
            }

            database.VersionIsValidVaule = ValidityOfContent.Existent;
            database.Version = context.Reals().GetText();
            return base.VisitVersionSection(context);
        }

        /// <summary>
        /// The Antlr framework calls the method to notify Parser Rule in g4 file(ecuAddress) was been found.
        /// </summary>
        /// <param name="context"></param>
        /// <returns></returns>
        public override object VisitEcuAddress([NotNull] VbfParser.EcuAddressContext context)
        {
            UInt16 data = 0;

            //Exception is not null means some errors happen and vbf file is invalid.
            if (context.exception != null)
            {
                Console.WriteLine(context.exception);
                database.Header.EcuAddressIsValidValue = ValidityOfContent.ParseError;
                return base.VisitEcuAddress(context);
            }

            foreach (ITerminalNode node in context.Hexadecimal())
            {
                try
                {
                    data = Convert.ToUInt16(node.GetText(), 16);
                }
                catch (Exception e)
                {
                    // Convert string to uint16 failed means vbf file is invalid.
                    Console.WriteLine(e.Message);
                    database.Header.EcuAddressIsValidValue = ValidityOfContent.ExistentButInvalid;
                    return base.VisitEcuAddress(context);
                }
                database.Header.addEcuAddress(data);
            }

            database.Header.EcuAddressIsValidValue = ValidityOfContent.Existent;
            return base.VisitEcuAddress(context);
        }

        /// <summary>
        /// The Antlr framework calls the method to notify Parser Rule in g4 file(erase) was been found.
        /// </summary>
        /// <param name="context"></param>
        /// <returns></returns>
        public override object VisitErase([NotNull] VbfParser.EraseContext context)
        {
            UInt32 data = 0;
            int count = 0;
            Block block = new Block();

            //Exception is not null means some errors happen and vbf file is invalid.
            if (context.exception != null)
            {
                Console.WriteLine(context.exception);
                database.Header.EraseIsValidValue = ValidityOfContent.ParseError;
                return base.VisitErase(context);
            }

            //If sw part type = SBL or GBL, the VBF file shall not contain the erase identifier.
            if (database.Header.SwPartTypeValue == SwPartType.SBL || 
                database.Header.SwPartTypeValue == SwPartType.GBL ||
                database.Header.SwPartTypeValue == SwPartType.Invalid)
            {
                Console.WriteLine("erase is invalid. ");
                database.Valid = false;
                return base.VisitErase(context);
            }

            // Walk through all value and gather into the erase address.
            foreach (ITerminalNode node in context.Hexadecimal())
            {
                try
                {
                    data = Convert.ToUInt32(node.GetText(), 16);
                    if (count % 2 == 0)
                        block.startAddress = data;
                    else
                        block.length = data;
                    count++;
                }
                catch (Exception e)
                {
                    // Convert string to uint32 failed means vbf file is invalid.
                    Console.WriteLine(e.Message);
                    database.Header.EraseIsValidValue = ValidityOfContent.ExistentButInvalid;
                    return base.VisitErase(context);
                }

                if (count % 2 == 0)
                    database.Header.addErase(block);
            }

            database.Header.EraseIsValidValue = ValidityOfContent.Existent;
            return base.VisitErase(context);
        }

        /// <summary>
        /// The Antlr framework calls the method to notify Parser Rule in g4 file(dataFormatIdentifier) was been found.
        /// </summary>
        /// <param name="context"></param>
        /// <returns></returns>
        public override object VisitDataFormatIdentifier([NotNull] VbfParser.DataFormatIdentifierContext context)
        {
            UInt16 data = 0;
            ITerminalNode node;
            //Exception is not null means some errors happen and vbf file is invalid.
            if (context.exception != null)
            {
                Console.WriteLine(context.exception);
                database.Header.DataFormatIdentifierIsValidValue = ValidityOfContent.ParseError;
                return base.VisitDataFormatIdentifier(context);
            }

            try
            {
                if (null != (node = context.Hexadecimal()))
                    data = Convert.ToUInt16(node.GetText(), 16);
                else if (null != (node = context.Binary()))
                {
                    if (node.GetText().Contains("0b"))
                        data = Convert.ToUInt16(node.GetText().Replace("0b", ""), 2);
                    else if (node.GetText().Contains("0B"))
                        data = Convert.ToUInt16(node.GetText().Replace("0B", ""), 2);
                }
                else if (null != (node = context.Decimal()))
                    data = Convert.ToUInt16(node.GetText(), 10);
            }
            catch (Exception e)
            {
                // Convert string to uint16 failed means vbf file is invalid.
                Console.WriteLine(e.Message);
                database.Header.DataFormatIdentifierIsValidValue = ValidityOfContent.ExistentButInvalid;
                return base.VisitDataFormatIdentifier(context);
            }

            database.Header.DataFormatIdentifierIsValidValue = ValidityOfContent.Existent;
            database.Header.DataFormatIdentifierValue = data;
            return base.VisitDataFormatIdentifier(context);
        }

        /// <summary>
        /// The Antlr framework calls the method to notify Parser Rule in g4 file(description) was been found.
        /// </summary>
        /// <param name="context"></param>
        /// <returns></returns>
        public override object VisitDescription([NotNull] VbfParser.DescriptionContext context)
        {
            string str;

            //Exception is not null means some errors happen and vbf file is invalid.
            if (context.exception != null)
            {
                Console.WriteLine(context.exception);
                database.Header.DescriptionIsValidValue = ValidityOfContent.ParseError;
                return base.VisitDescription(context);
            }

            // Walk through all value and gather into the description.
            foreach (ITerminalNode node in context.String())
            {
                //Remove the double-quoted in the string.
                str = node.GetText().Replace("\"", "");
                database.Header.addDescritption(str);
            }

            database.Header.DescriptionIsValidValue = ValidityOfContent.Existent;
            return base.VisitDescription(context);
        }

        /// <summary>
        /// The Antlr framework calls the method to notify Parser Rule in g4 file(frameFormat) was been found.
        /// </summary>
        /// <param name="context"></param>
        /// <returns></returns>
        public override object VisitFrameFormat([NotNull] VbfParser.FrameFormatContext context)
        {
            //Exception is not null means some errors happen and vbf file is invalid.
            if (context.exception != null)
            {
                Console.WriteLine(context.exception);
                database.Header.FrameFormatIsValidValue = ValidityOfContent.ParseError;
                return base.VisitFrameFormat(context);
            }

            //Get the frame format string from the tree and compare the string.
            string str = context.children[2].GetText();
            if (str.Equals("CAN_STANDARD"))
                database.Header.FrameFormatValue = FrameFormat.CAN_STANDARD;
            else if (str.Equals("CAN_EXTENDED"))
                database.Header.FrameFormatValue = FrameFormat.CAN_EXTENDED;
            else
            {
                database.Header.FrameFormatValue = FrameFormat.Invalid;
                database.Header.FrameFormatIsValidValue = ValidityOfContent.ExistentButInvalid;
            }

            database.Header.FrameFormatIsValidValue = ValidityOfContent.Existent;
            return base.VisitFrameFormat(context);
        }

        /// <summary>
        /// The Antlr framework calls the method to notify Parser Rule in g4 file(fileChecksum) was been found.
        /// </summary>
        /// <param name="context"></param>
        /// <returns></returns>
        public override object VisitFileChecksum([NotNull] VbfParser.FileChecksumContext context)
        {
            UInt32 data = 0;

            //Exception is not null means some errors happen and vbf file is invalid.
            if (context.exception != null)
            {
                Console.WriteLine(context.exception);
                database.Header.FileCheckSumIsValidValue = ValidityOfContent.ParseError;
                return base.VisitFileChecksum(context);
            }

            try
            {
                data = Convert.ToUInt32(context.Hexadecimal().GetText(), 16);
            }
            catch (Exception e)
            {
                // Convert string to uint32 failed means vbf file is invalid.
                Console.WriteLine(e.Message);
                database.Header.FileCheckSumIsValidValue = ValidityOfContent.ExistentButInvalid;
                return base.VisitFileChecksum(context);
            }

            database.Header.FileCheckSumIsValidValue = ValidityOfContent.Existent;
            database.Header.FileCheckSumValue = data;
            return base.VisitFileChecksum(context);
        }

        /// <summary>
        /// The Antlr framework calls the method to notify Parser Rule in g4 file(headerSection) was been found.
        /// </summary>
        /// <param name="context"></param>
        /// <returns></returns>
        public override object VisitHeaderSection([NotNull] VbfParser.HeaderSectionContext context)
        {
            //Exception is not null means some errors happen and vbf file is invalid.
            if (context.exception != null)
            {
                Console.WriteLine(context.exception);
                database.Header.HeaderIsValidValue = ValidityOfContent.ParseError;
                return base.VisitHeaderSection(context);
            }

            database.Header.HeaderIsValidValue = ValidityOfContent.Existent;
            return base.VisitHeaderSection(context);
        }

        /// <summary>
        /// The Antlr framework calls the method to notify Parser Rule in g4 file(swPartNnumber) was been found.
        /// </summary>
        /// <param name="context"></param>
        /// <returns></returns>
        public override object VisitSwPartNumber([NotNull] VbfParser.SwPartNumberContext context)
        {
            string str;

            //Exception is not null means some errors happen and vbf file is invalid.
            if (context.exception != null)
            {
                Console.WriteLine(context.exception);
                database.Header.SwPartNumberIsValidValue = ValidityOfContent.ParseError;
                return base.VisitSwPartNumber(context);
            }

            // Walk through all value and gather into the sw part number.
            foreach (ITerminalNode node in context.String())
            {
                //Remove the double-quoted in the string.
                str = node.GetText().Replace("\"", "");
                database.Header.addSwPartNumber(str);
            }

            database.Header.SwPartNumberIsValidValue = ValidityOfContent.Existent;
            return base.VisitSwPartNumber(context);
        }

        /// <summary>
        /// The Antlr framework calls the method to notify Parser Rule in g4 file(omit) was been found.
        /// </summary>
        /// <param name="context"></param>
        /// <returns></returns>
        public override object VisitOmit([NotNull] VbfParser.OmitContext context)
        {
            UInt32 data = 0;
            int count = 0;
            Block block = new Block();

            //Exception is not null means some errors happen and vbf file is invalid.
            if (context.exception != null)
            {
                Console.WriteLine(context.exception);
                database.Header.OmitIsValidValue = ValidityOfContent.ParseError;
                return base.VisitOmit(context);
            }

            // Walk through all value and gather into the omit address.
            foreach (ITerminalNode node in context.Hexadecimal())
            {
                try
                {
                    data = Convert.ToUInt32(node.GetText(), 16);
                    if (count % 2 == 0)
                        block.startAddress = data;
                    else
                        block.length = data;
                    count++;
                }
                catch (Exception e)
                {
                    // Convert string to uint32 failed means vbf file is invalid.
                    Console.WriteLine(e.Message);
                    database.Header.OmitIsValidValue = ValidityOfContent.ExistentButInvalid;
                    return base.VisitOmit(context);
                }

                if (count % 2 == 0)
                    database.Header.addOmit(block);
            }

            database.Header.OmitIsValidValue = ValidityOfContent.Existent;
            return base.VisitOmit(context);
        }

        /// <summary>
        /// The Antlr framework calls the method to notify Parser Rule in g4 file(call) was been found.
        /// </summary>
        /// <param name="context"></param>
        /// <returns></returns>
        public override object VisitCall([NotNull] VbfParser.CallContext context)
        {
            UInt32 data = 0;
            //Exception is not null means some errors happen and vbf file is invalid.
            if (context.exception != null)
            {
                Console.WriteLine(context.exception);
                database.Header.CallIsValidValue = ValidityOfContent.ParseError;
                return base.VisitCall(context);
            }

            try
            {
                data = Convert.ToUInt32(context.Hexadecimal().GetText(), 16);
            }
            catch (Exception e)
            {
                // Convert string to uint32 failed means vbf file is invalid.
                Console.WriteLine(e.Message);
                database.Header.CallIsValidValue = ValidityOfContent.ExistentButInvalid;
                return base.VisitCall(context);
            }

            database.Header.CallIsValidValue = ValidityOfContent.Existent;
            database.Header.CallValue = data;
            return base.VisitCall(context);
        }

        /// <summary>
        /// The Antlr framework calls the method to notify Parser Rule in g4 file(swPartType) was been found.
        /// </summary>
        /// <param name="context"></param>
        /// <returns></returns>
        public override object VisitSwPartType([NotNull] VbfParser.SwPartTypeContext context)
        {
            //Exception is not null means some errors happen and vbf file is invalid.
            if (context.exception != null)
            {
                Console.WriteLine(context.exception);
                database.Header.SwPartTypeIsValidValue = ValidityOfContent.ParseError;
                return base.VisitSwPartType(context);
            }

            //Get the frame format string from the tree and compare the string.
            string str = context.children[2].GetText();
            if (str.Equals("CARCFG"))
                database.Header.SwPartTypeValue = SwPartType.CARCFG;
            else if (str.Equals("CUSTOM"))
                database.Header.SwPartTypeValue = SwPartType.CUSTOM;
            else if (str.Equals("DATA"))
                database.Header.SwPartTypeValue = SwPartType.DATA;
            else if (str.Equals("EXE"))
                database.Header.SwPartTypeValue = SwPartType.EXE;
            else if (str.Equals("GBL"))
                database.Header.SwPartTypeValue = SwPartType.GBL;
            else if (str.Equals("SBL"))
                database.Header.SwPartTypeValue = SwPartType.SBL;
            else if (str.Equals("SIGCFG"))
                database.Header.SwPartTypeValue = SwPartType.SIGCFG;
            else if (str.Equals("TEST"))
                database.Header.SwPartTypeValue = SwPartType.TEST;
            else
            {
                database.Header.SwPartTypeValue = SwPartType.Invalid;
                database.Header.SwPartTypeIsValidValue = ValidityOfContent.ExistentButInvalid;
            }

            database.Header.SwPartTypeIsValidValue = ValidityOfContent.Existent;
            return base.VisitSwPartType(context);
        }


    }
}
