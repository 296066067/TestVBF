using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Antlr4.Runtime;
using Antlr4.Runtime.Tree;

namespace VBF
{
    /// <summary>
    /// The definition of sw part type.
    /// </summary>
    public enum SwPartType
    {
        Invalid,
        CARCFG,
        CUSTOM,
        DATA,
        EXE,
        GBL,
        Test,
        SIGCFG,
        TEST
    }

    /// <summary>
    /// The definition of frame format.
    /// </summary>
    public enum FrameFormat
    {
        Invalid,
        CAN_STANDARD,
        CAN_EXTENDED
    }

    /// <summary>
    /// The validity of content in header.
    /// </summary>
    public enum ValidityOfContent
    {
        NonExistent,
        Existent,
        ParseError,
        ExistentAndValid,
        ExistentButInvalid
    }

    /// <summary>
    /// The definition of data block.
    /// </summary>
    public struct Block
    {
        public UInt32 startAddress;
        public UInt32 length;
    };

    /// <summary>
    /// The class is used describe the header section for vbf file.
    /// </summary>
    public class HeaderSection
    {
        /// <summary>
        /// The description of header section. It is optional content.
        /// </summary>
        protected List<string> description = new List<string>();

        /// <summary>
        /// The flag of description valid.
        /// </summary>
        protected ValidityOfContent descriptionIsValid = ValidityOfContent.NonExistent;

        /// <summary>
        /// The swPartNumber of header section. It is mandatory content.
        /// </summary>
        protected List<string> swPartNumber = new List<string>();

        /// <summary>
        /// The flag of swPartNumber valid.
        /// </summary>
        protected ValidityOfContent swPartNumberIsValid = ValidityOfContent.NonExistent;

        /// <summary>
        /// The swPartType of header section. It is mandatory content.
        /// </summary>
        protected SwPartType swPartType = SwPartType.Invalid;

        /// <summary>
        /// The flag of swPartType valid.
        /// </summary>
        protected ValidityOfContent swPartTypeIsValid = ValidityOfContent.NonExistent;

        /// <summary>
        /// The dataFormatIdentifier of header section. It is optional content.
        /// </summary>
        protected UInt16 dataFormatIdentifier = 0;

        /// <summary>
        /// The flag of dataFormatIdentifier valid.
        /// </summary>
        protected ValidityOfContent dataFormatIdentifierIsValid = ValidityOfContent.NonExistent;

        /// <summary>
        /// The ceuAddress of header section. It is mandatory content.
        /// </summary>
        protected List<UInt16> ecuAddress = new List<UInt16>();

        /// <summary>
        /// The flag of ecuAddress valid.
        /// </summary>
        protected ValidityOfContent ecuAddressIsValid = ValidityOfContent.NonExistent;

        /// <summary>
        /// The frameFormat of header section. It is mandatory content.
        /// </summary>
        protected FrameFormat frameFormat;

        /// <summary>
        /// The flag of frameFormat valid. It is mandatory content.
        /// </summary>
        protected ValidityOfContent frameFormatIsValid = ValidityOfContent.NonExistent;

        /// <summary>
        /// The erase of header section. It is optional content.
        /// </summary>
        protected List<Block> erase = new List<Block>();

        /// <summary>
        /// The flag of erase valid.
        /// </summary>
        protected ValidityOfContent eraseIsValid = ValidityOfContent.NonExistent;

        /// <summary>
        /// The omit of header section. It is optional content.
        /// </summary>
        protected List<Block> omit = new List<Block>();

        /// <summary>
        /// The flag of omit valid.
        /// </summary>
        protected ValidityOfContent omitIsValid = ValidityOfContent.NonExistent;

        /// <summary>
        /// The call of header section. It is optional content.
        /// </summary>
        protected UInt32 call;

        /// <summary>
        /// The flag of call valid.
        /// </summary>
        protected ValidityOfContent callIsValid = ValidityOfContent.NonExistent;

        /// <summary>
        /// The fileCheckSum of header section. It is mandatory content.
        /// </summary>
        protected UInt32 fileCheckSum;

        /// <summary>
        /// The flag of fileCheckSum valid.
        /// </summary>
        protected ValidityOfContent fileCheckSumIsValid = ValidityOfContent.NonExistent;

        /// <summary>
        /// The flag of head section valid.
        /// </summary>
        protected ValidityOfContent headerIsValid = ValidityOfContent.NonExistent;

        /// <summary>
        /// The method is used to add a new string into the description.
        /// </summary>
        /// <param name="des"></param>
        /// <returns></returns>
        public int addDescritption(string str)
        {
            // Check the input.
            if (null == str)
                return -1;

            description.Add(str);
            return 0;
        }

        public List<string> DescriptionValue
        {
            get
            {
                return description;
            }
        }

        /// <summary>
        /// The method is used to add a new string into the sw part number.
        /// </summary>
        /// <param name="str"></param>
        /// <returns></returns>
        public int addSwPartNumber(string str)
        {
            // Check the input.
            if (null == str)
                return -1;

            swPartNumber.Add(str);
            return 0;
        }

        public List<string> SwPartNumberValue
        {
            get
            {
                return swPartNumber;
            }
        }

        /// <summary>
        /// Gets or set the sw part type of the vbf file.
        /// </summary>
        public SwPartType SwPartTypeValue
        {
            get
            {
                return swPartType;
            }
            set
            {
                swPartType = value;
            }
        }

        /// <summary>
        /// Gets or set the data format identifier of the vbf file.
        /// </summary>
        public UInt16 DataFormatIdentifierValue
        {
            get
            {
                return dataFormatIdentifier;
            }
            set
            {
                dataFormatIdentifier = value;
            }
        }

        /// <summary>
        /// The method is used to add a new address into the ecu address.
        /// </summary>
        /// <param name="str"></param>
        /// <returns></returns>
        public int addEcuAddress(UInt16 add)
        {
            ecuAddress.Add(add);
            return 0;
        }

        public List<UInt16> EcuAddressValue
        {
            get
            {
                return ecuAddress;
            }
        }

        /// <summary>
        /// Gets or set the frame format of the vbf file.
        /// </summary>
        public FrameFormat FrameFormatValue
        {
            get
            {
                return frameFormat;
            }
            set
            {
                frameFormat = value;
            }
        }

        /// <summary>
        /// The method is used to add a erase address into erase.
        /// </summary>
        /// <param name="str"></param>
        /// <returns></returns>
        public int addErase(Block block)
        {
            erase.Add(block);
            return 0;
        }

        public List<Block> EraseValue
        {
            get
            {
                return erase;
            }
        }

        /// <summary>
        /// The method is used to add a omit address into omit.
        /// </summary>
        /// <param name="str"></param>
        /// <returns></returns>
        public int addOmit(Block block)
        {
            omit.Add(block);
            return 0;
        }

        public List<Block> OmitValue
        {
            get
            {
                return omit;
            }
        }

        /// <summary>
        /// Gets or set the call address of the vbf file.
        /// </summary>
        public UInt32 CallValue
        {
            get
            {
                return call;
            }
            set
            {
                call = value;
            }
        }

        /// <summary>
        /// Gets or set the call address of the vbf file.
        /// </summary>
        public UInt32 FileCheckSumValue
        {
            get
            {
                return fileCheckSum;
            }
            set
            {
                fileCheckSum = value;
            }
        }

        public ValidityOfContent DescriptionIsValidValue
        {
            get
            {
                return descriptionIsValid;
            }
            set
            {
                descriptionIsValid = value;
            }
        }

        public ValidityOfContent SwPartNumberIsValidValue
        {
            get
            {
                return swPartNumberIsValid;
            }
            set
            {
                swPartNumberIsValid = value;
            }
        }

        public ValidityOfContent SwPartTypeIsValidValue
        {
            get
            {
                return swPartTypeIsValid;
            }
            set
            {
                swPartTypeIsValid = value;
            }
        }

        public ValidityOfContent DataFormatIdentifierIsValidValue
        {
            get
            {
                return dataFormatIdentifierIsValid;
            }
            set
            {
                dataFormatIdentifierIsValid = value;
            }
        }

        public ValidityOfContent EcuAddressIsValidValue
        {
            get
            {
                return ecuAddressIsValid;
            }
            set
            {
                ecuAddressIsValid = value;
            }
        }

        public ValidityOfContent FrameFormatIsValidValue
        {
            get
            {
                return frameFormatIsValid;
            }
            set
            {
                frameFormatIsValid = value;
            }
        }

        public ValidityOfContent EraseIsValidValue
        {
            get
            {
                return eraseIsValid;
            }
            set
            {
                eraseIsValid = value;
            }
        }

        public ValidityOfContent OmitIsValidValue
        {
            get
            {
                return omitIsValid;
            }
            set
            {
                omitIsValid = value;
            }
        }

        public ValidityOfContent CallIsValidValue
        {
            get
            {
                return callIsValid;
            }
            set
            {
                callIsValid = value;
            }
        }

        public ValidityOfContent FileCheckSumIsValidValue
        {
            get
            {
                return fileCheckSumIsValid;
            }
            set
            {
                fileCheckSumIsValid = value;
            }
        }

        public ValidityOfContent HeaderIsValidValue
        {
            get
            {
                return headerIsValid;
            }
            set
            {
                headerIsValid = value;
            }

        }
        /// <summary>
        /// The method is used to check the valid of description.
        /// </summary>
        /// <returns></returns>
        protected ValidityOfContent checkDescriptionIsValid()
        {
            if (descriptionIsValid == ValidityOfContent.NonExistent ||
                descriptionIsValid == ValidityOfContent.ParseError)
                return descriptionIsValid;

            if (descriptionIsValid == ValidityOfContent.Existent)
            {
                //The description contain a maximum of 16 rows, with each row containing a maximum of 80 characters.
                for (int i = 0; i < description.Count(); i++)
                {
                    if (description.ElementAt(i).Length > 80 || i > 15)
                        return ValidityOfContent.ExistentButInvalid;
                }
            }
            return ValidityOfContent.ExistentAndValid;
        }

        /// <summary>
        /// The method is used to check the valid of swPartNumber.
        /// </summary>
        /// <returns></returns>
        protected ValidityOfContent checkSwPartNumberIsValid()
        {
            string str;

            if (swPartNumberIsValid == ValidityOfContent.NonExistent ||
                swPartNumberIsValid == ValidityOfContent.ParseError)
                return swPartNumberIsValid;

            for (int i = 0; i < swPartNumber.Count(); i++)
            {
                str = swPartNumber.ElementAt(i);
                //The sw part number shall be contained in quotes and shall consist of a maximum of 24 characters(bytes).
                //No white space characters or comments are allowed within these quotes.
                if (str.Contains(" ") || str.Length > 24 || str.Contains("/*") || str.Contains("*/") || i > 1)
                    return ValidityOfContent.ExistentButInvalid;
            }
            return ValidityOfContent.ExistentAndValid;
        }

        /// <summary>
        /// The method is used to check the valid of swPartType.
        /// </summary>
        /// <returns></returns>
        protected ValidityOfContent checkSwPartType()
        {
            if (swPartTypeIsValid == ValidityOfContent.NonExistent ||
                swPartTypeIsValid == ValidityOfContent.ParseError ||
                swPartTypeIsValid == ValidityOfContent.ExistentButInvalid)
                return swPartTypeIsValid;

            if (swPartTypeIsValid == ValidityOfContent.Existent)
            {
                if (swPartType == SwPartType.Invalid)
                    return ValidityOfContent.ExistentButInvalid;
            }
            return ValidityOfContent.ExistentAndValid;
        }

        /// <summary>
        /// The method is used to check the valid of dataFormatIdentifier.
        /// </summary>
        /// <returns></returns>
        protected ValidityOfContent checkDataFormatIdentifier()
        {
            if (dataFormatIdentifierIsValid == ValidityOfContent.NonExistent ||
                dataFormatIdentifierIsValid == ValidityOfContent.ParseError ||
                dataFormatIdentifierIsValid == ValidityOfContent.ExistentButInvalid)
                return dataFormatIdentifierIsValid;

            if (dataFormatIdentifierIsValid == ValidityOfContent.Existent)
            {
                //Valid values for the data format identifier are one byte long with a range of 0x00 to 0xFF.
                if (dataFormatIdentifier > 0xFF)
                    return ValidityOfContent.ExistentButInvalid;
            }
            return ValidityOfContent.ExistentAndValid;
        }

        /// <summary>
        /// The method is used to check the valid of ecuAddress.
        /// </summary>
        /// <returns></returns>
        protected ValidityOfContent checkEcuAddress()
        {
            if (ecuAddressIsValid == ValidityOfContent.NonExistent ||
                ecuAddressIsValid == ValidityOfContent.ParseError ||
                ecuAddressIsValid == ValidityOfContent.ExistentButInvalid)
                return ecuAddressIsValid;

            if (ecuAddressIsValid == ValidityOfContent.Existent)
            {
                if (frameFormat == FrameFormat.CAN_EXTENDED)
                {
                    if (ecuAddress.Count() == 1)
                    {
                        if (ecuAddress.ElementAt(0) > 0xFF)
                            return ValidityOfContent.ExistentButInvalid;
                    }
                    if (ecuAddress.Count() == 3)
                    {
                        if (ecuAddress.ElementAt(0) > 0xFF ||
                            ecuAddress.ElementAt(1) > 0x07 ||
                            ecuAddress.ElementAt(2) > 0xFF)
                            return ValidityOfContent.ExistentButInvalid;
                    }
                }
                else if (frameFormat == FrameFormat.CAN_STANDARD)
                {
                    if (ecuAddress.Count() == 1)
                    {
                        if (ecuAddress.ElementAt(0) > 0x7FF)
                            return ValidityOfContent.ExistentButInvalid;
                    }
                    if (ecuAddress.Count() == 3)
                    {
                        if (ecuAddress.ElementAt(0) > 0x7FF ||
                            ecuAddress.ElementAt(1) > 0xFF ||
                            ecuAddress.ElementAt(2) > 0xFF)
                            return ValidityOfContent.ExistentButInvalid;
                    }
                }
                else
                    return ValidityOfContent.ExistentButInvalid;
            }
            return ValidityOfContent.ExistentAndValid;
        }

        /// <summary>
        /// The method is used to check the valid of frameFormat.
        /// </summary>
        /// <returns></returns>
        protected ValidityOfContent checkFrameFormat()
        {
            if (frameFormatIsValid == ValidityOfContent.NonExistent ||
                frameFormatIsValid == ValidityOfContent.ParseError ||
                frameFormatIsValid == ValidityOfContent.ExistentButInvalid)
                return frameFormatIsValid;

            if (frameFormatIsValid == ValidityOfContent.Existent)
            {
                if (frameFormat == FrameFormat.Invalid)
                    return ValidityOfContent.ExistentButInvalid;
            }
            return ValidityOfContent.ExistentAndValid;
        }

        /// <summary>
        /// The method is used to check the valid of erase.
        /// </summary>
        /// <returns></returns>
        protected ValidityOfContent checkErase()
        {
            if (eraseIsValid == ValidityOfContent.NonExistent ||
                eraseIsValid == ValidityOfContent.ParseError ||
                eraseIsValid == ValidityOfContent.ExistentButInvalid)
                return eraseIsValid;

            if (eraseIsValid == ValidityOfContent.Existent)
            {
                UInt64 data = 0;
                for (int i = 0; i < erase.Count(); i++)
                {
                    // Address overflow.
                    data = (UInt64)erase.ElementAt(i).startAddress + (UInt64)erase.ElementAt(i).length;
                    if (data > 0xFFFFFFFF)
                        return ValidityOfContent.ExistentButInvalid;
                }
            }
            return ValidityOfContent.ExistentAndValid;
        }

        /// <summary>
        /// The method is used to check the valid of omit.
        /// </summary>
        /// <returns></returns>
        protected ValidityOfContent checkOmit()
        {
            if (omitIsValid == ValidityOfContent.NonExistent ||
                omitIsValid == ValidityOfContent.ParseError ||
                omitIsValid == ValidityOfContent.ExistentButInvalid)
                return omitIsValid;

            if (omitIsValid == ValidityOfContent.Existent)
            {
                if (eraseIsValid == ValidityOfContent.ExistentAndValid)
                {
                    for (int i = 0; i < omit.Count(); i++)
                    {
                        bool isFound = false;
                        for (int j = 0; j < erase.Count(); j++)
                        {
                            if (erase.ElementAt(j).startAddress == omit.ElementAt(i).startAddress &&
                                erase.ElementAt(j).length == omit.ElementAt(i).length)
                            {
                                isFound = true;
                            }
                        }
                        if (!isFound)
                            return ValidityOfContent.ExistentButInvalid;
                    }
                }
            }
            return ValidityOfContent.ExistentAndValid;
        }

        /// <summary>
        /// The method is used to check the valid of call.
        /// </summary>
        /// <returns></returns>
        protected ValidityOfContent checkCall()
        {
            if (callIsValid == ValidityOfContent.ParseError ||
                callIsValid == ValidityOfContent.ExistentButInvalid)
                return callIsValid;

            //The call entry is mandatory in VBF files with sw part type identifier values equal to SBL or GBL and optional
            //in VBF files with sw part type equal to TEST.
            //For all other identifier values of sw part type, the call entry is not allowed.
            if (swPartType == SwPartType.Test || swPartType == SwPartType.GBL)
            {
                if (callIsValid == ValidityOfContent.NonExistent)
                    return ValidityOfContent.ExistentButInvalid;
            }
            else if (swPartType == SwPartType.Test)
            {
                
            }
            else
            {
                if (callIsValid == ValidityOfContent.Existent)
                    return ValidityOfContent.ExistentButInvalid;
            }

            if (callIsValid == ValidityOfContent.NonExistent)
                return callIsValid;
            return ValidityOfContent.ExistentAndValid;
        }

        /// <summary>
        /// The method is used to check the valid of fileCheckSum.
        /// </summary>
        /// <returns></returns>
        protected ValidityOfContent checkFileCheckSum()
        {
            if (fileCheckSumIsValid == ValidityOfContent.NonExistent ||
                fileCheckSumIsValid == ValidityOfContent.ParseError ||
                fileCheckSumIsValid == ValidityOfContent.ExistentButInvalid)
                return fileCheckSumIsValid;

            if (fileCheckSumIsValid == ValidityOfContent.Existent)
            {

            }
            return ValidityOfContent.ExistentAndValid;
        }

        public ValidityOfContent checkHeaderIsValid()
        {
            if (headerIsValid == ValidityOfContent.NonExistent ||
                headerIsValid == ValidityOfContent.ParseError)
                return headerIsValid;

            if (headerIsValid == ValidityOfContent.Existent)
            {
                descriptionIsValid = checkDescriptionIsValid();
                swPartNumberIsValid = checkSwPartNumberIsValid();
                swPartTypeIsValid = checkSwPartType();
                dataFormatIdentifierIsValid = checkDataFormatIdentifier();
                frameFormatIsValid = checkFrameFormat();
                ecuAddressIsValid = checkEcuAddress();
                eraseIsValid = checkErase();
                omitIsValid = checkOmit();
                callIsValid = checkCall();
                fileCheckSumIsValid = checkFileCheckSum();

                // The following contents are mandatory requirements, must be existent and valid.
                if (swPartNumberIsValid != ValidityOfContent.ExistentAndValid ||
                    swPartTypeIsValid != ValidityOfContent.ExistentAndValid ||
                    ecuAddressIsValid != ValidityOfContent.ExistentAndValid ||
                    frameFormatIsValid != ValidityOfContent.ExistentAndValid ||
                    fileCheckSumIsValid != ValidityOfContent.ExistentAndValid)
                    return ValidityOfContent.ExistentButInvalid;

                // The following contents are optional, but existent and invalid.
                if (descriptionIsValid == ValidityOfContent.ExistentButInvalid ||
                    dataFormatIdentifierIsValid == ValidityOfContent.ExistentButInvalid ||
                    eraseIsValid == ValidityOfContent.ExistentButInvalid ||
                    omitIsValid == ValidityOfContent.ExistentButInvalid ||
                    callIsValid == ValidityOfContent.ExistentButInvalid)
                    return ValidityOfContent.ExistentButInvalid;
            }

            return ValidityOfContent.ExistentAndValid;
        }
    }

    /// <summary>
    /// The class is used describe the database for vbf file.
    /// </summary>
    public class Database
    {
        /// <summary>
        /// The version of the VBF file.
        /// </summary>
        protected string version;

        /// <summary>
        /// The flag of version valid.
        /// </summary>
        protected ValidityOfContent versionIsValid = ValidityOfContent.NonExistent;

        /// <summary>
        /// The header section of the VBF file.
        /// </summary>
        protected HeaderSection header = new HeaderSection();

        /// <summary>
        /// The valid flag of vbf file.
        /// </summary>
        protected bool databaseIsValid = true;

        /// <summary>
        /// Gets or set the version of the vbf file.
        /// </summary>
        public string Version
        {
            get
            {
                return version;
            }
            set
            {
                version = value;
            }
        }

        /// <summary>
        /// Gets or set the valid flag of the vbf file.
        /// </summary>
        public bool Valid
        {
            get
            {
                return databaseIsValid;
            }
            set
            {
                databaseIsValid = value;
            }
        }

        /// <summary>
        /// Gets or set the valid flag of the vbf file.
        /// </summary>
        public HeaderSection Header
        {
            get
            {
                return header;
            }
        }

        public ValidityOfContent VersionIsValidVaule
        {
            get
            {
                return versionIsValid;
            }
            set
            {
                versionIsValid = value;
            }
        }

        /// <summary>
        /// The method is used to check the valid of version.
        /// </summary>
        /// <returns></returns>
        protected ValidityOfContent checkVersionIsValid()
        {
            if (versionIsValid == ValidityOfContent.NonExistent ||
                versionIsValid == ValidityOfContent.ParseError)
                return versionIsValid;

            if (versionIsValid == ValidityOfContent.Existent)
            {
                if (version != "3.0")
                    return ValidityOfContent.ExistentButInvalid;
            }
            return ValidityOfContent.ExistentAndValid;
        }

        /// <summary>
        /// The method is used to check the valid of database.
        /// </summary>
        /// <returns></returns>
        public bool checkDatabaseIsValid()
        {
            // Version and header must be existent and valid.
            if (ValidityOfContent.ExistentAndValid == (versionIsValid = checkVersionIsValid()) &&
                ValidityOfContent.ExistentAndValid == (header.HeaderIsValidValue = header.checkHeaderIsValid()))
                return true;

            return false;
        }

        /// <summary>
        /// The method is used to load the vbf file from the given path.
        /// </summary>
        /// <param name="path"></param>
        /// <returns></returns>
        public static Database Load(string path)
        {
            // Create antlr input stream. 
            AntlrInputStream stream = new AntlrFileStream(path);

            // Create the lexer. 
            VbfLexer lexer = new VbfLexer(stream);

            // Start syntax analysing. 
            CommonTokenStream tokens = new CommonTokenStream(lexer);

            // Create the parser to start sematic analysing. 
            VbfParser parser = new VbfParser(tokens);
            //parser.RemoveErrorListeners();
            //parser.AddErrorListener(new VbfErrorListener());

            // Get the parse tree.
            IParseTree tree = parser.database();

            // For test purpose, print out the parse tree.
            //Console.Write(tree.ToStringTree());
            VbfVisitor loader = new VbfVisitor();

            loader.Visit(tree);

            Database d = loader.Database;
            d.Valid = d.checkDatabaseIsValid();
            return d;
        }

    }
}
