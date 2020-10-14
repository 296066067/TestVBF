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
        SBL,
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
        /// The description of header section.
        /// </summary>
        protected List<string> description = new List<string>();

        /// <summary>
        /// The swPartNumber of header section.
        /// </summary>
        protected List<string> swPartNumber = new List<string>();

        /// <summary>
        /// The swPartType of header section.
        /// </summary>
        protected SwPartType swPartType;

        /// <summary>
        /// The dataFormatIdentifier of header section.
        /// </summary>
        protected UInt16 dataFormatIdentifier;

        /// <summary>
        /// The ceuAddress of header section.
        /// </summary>
        protected List<UInt16> ecuAddress = new List<UInt16>();

        /// <summary>
        /// The frameFormat of header section.
        /// </summary>
        protected FrameFormat frameFormat;

        /// <summary>
        /// The erase of header section.
        /// </summary>
        protected List<Block> erase = new List<Block>();

        /// <summary>
        /// The omit of header section.
        /// </summary>
        protected List<Block> omit = new List<Block>();

        /// <summary>
        /// The call of header section.
        /// </summary>
        protected UInt32 call;

        /// <summary>
        /// The fileCheckSum of header section.
        /// </summary>
        protected UInt32 fileCheckSum;

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
        /// The header section of the VBF file.
        /// </summary>
        protected HeaderSection header = new HeaderSection();

        /// <summary>
        /// The valid flag of vbf file.
        /// </summary>
        protected bool isValid = true;

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
                return isValid;
            }
            set
            {
                isValid = value;
            }
        }

        /// <summary>
        /// 
        /// Gets or set the valid flag of the vbf file.
        /// </summary>
        public HeaderSection Header
        {
            get
            {
                return header;
            }
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
             Console.Write(tree.ToStringTree());
            VbfVisitor loader = new VbfVisitor();

            loader.Visit(tree);

            return loader.Database;
        }

    }
}
