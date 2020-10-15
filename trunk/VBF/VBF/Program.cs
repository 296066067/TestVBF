using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VBF
{
    class Program
    {
        static void print_database()
        {
            string path = "E:\\Sumarte\\Code\\vba3_VBF\\trunk\\VBF\\VBF\\test.vbf";
            Database database = Database.Load(path);

            Console.WriteLine("\r\n vbf file valid : {0}, version_section valid : {1}, header_section valid : {2} \r\n", database.Valid, database.VersionIsValidVaule, database.Header.HeaderIsValidValue);

            Console.WriteLine("\r\n version valid : {0}", database.VersionIsValidVaule);
            Console.WriteLine(" version value : {0} \r\n", database.Version);

            Console.WriteLine("\r\n description valid : {0} ", database.Header.DescriptionIsValidValue);
            for (int i = 0; i < database.Header.DescriptionValue.Count(); i++)
            {
                Console.WriteLine(" description value : {0}", database.Header.DescriptionValue.ElementAt(i));
            }

            Console.WriteLine("\r\n sw_part_number valid : {0} ", database.Header.SwPartNumberIsValidValue);
            for (int i = 0; i < database.Header.SwPartNumberValue.Count(); i++)
            {
                Console.WriteLine(" sw_part_number value : {0}", database.Header.SwPartNumberValue.ElementAt(i));
            }

            Console.WriteLine("\r\n sw_part_type valid : {0}", database.Header.SwPartTypeIsValidValue);
            Console.WriteLine(" sw_part_type value : {0} \r\n", database.Header.SwPartTypeValue);

            Console.WriteLine("\r\n data_format_identifier valid : {0}", database.Header.DataFormatIdentifierIsValidValue);
            Console.WriteLine(" data_format_identifier value : {0:x} \r\n", database.Header.DataFormatIdentifierValue);

            Console.WriteLine("\r\n ecu_address valid : {0} ", database.Header.EcuAddressIsValidValue);
            for (int i = 0; i < database.Header.EcuAddressValue.Count(); i++)
            {
                Console.WriteLine(" ecu_address value : {0:x}", database.Header.EcuAddressValue.ElementAt(i));
            }

            Console.WriteLine("\r\n frame_format valid : {0}", database.Header.FrameFormatIsValidValue);
            Console.WriteLine(" frame_format value : {0} \r\n", database.Header.FrameFormatValue);

            Console.WriteLine("\r\n erase valid : {0} ", database.Header.EraseIsValidValue);
            for (int i = 0; i < database.Header.EraseValue.Count(); i++)
            {
                Console.WriteLine(" erase value : {0:x} {1:x}", database.Header.EraseValue.ElementAt(i).startAddress, database.Header.EraseValue.ElementAt(i).length);
            }

            Console.WriteLine("\r\n omit valid : {0} ", database.Header.OmitIsValidValue);
            for (int i = 0; i < database.Header.OmitValue.Count(); i++)
            {
                Console.WriteLine(" omit value : {0:x} {1:x}", database.Header.OmitValue.ElementAt(i).startAddress, database.Header.OmitValue.ElementAt(i).length);
            }

            Console.WriteLine("\r\n call valid : {0}", database.Header.CallIsValidValue);
            Console.WriteLine(" call value : {0:x} \r\n", database.Header.CallValue);

            Console.WriteLine("\r\n file_checksum valid : {0}", database.Header.FileCheckSumIsValidValue);
            Console.WriteLine(" file_checksum value : {0:x} \r\n", database.Header.FileCheckSumValue);
        }

        static void Main(string[] args)
        {
            int i = 0;
            print_database();
            while (true)
            {
                i = 1;
            }
        }
    }
}
