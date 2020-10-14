using Antlr4.Runtime;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Antlr4.Runtime.Misc;

namespace VBF
{
    /// <summary>
    /// The class is used to listen the error event from the Antlr parser and lexer.
    /// </summary>
    public class VbfErrorListener : BaseErrorListener
    {


        /// <summary>
        /// 
        /// </summary>
        /// <param name="recognizer"></param>
        /// <param name="offendingSymbol"></param>
        /// <param name="line"></param>
        /// <param name="charPositionInLine"></param>
        /// <param name="msg"></param>
        /// <param name="e"></param>
        public override void SyntaxError(
            [NotNull] IRecognizer recognizer,
            [Nullable] IToken offendingSymbol,
            int line,
            int charPositionInLine,
            [NotNull] string msg,
            [Nullable] RecognitionException e)
        {
            // base.SyntaxError(recognizer, offendingSymbol, line, charPositionInLine, msg, e);
            IList<string> stack = (recognizer as Parser).GetRuleInvocationStack();
            IEnumerable<string> messages = stack.Reverse();

            foreach (string item in messages)
            {
                Console.WriteLine("rule stack: {0}", item);
            }

            Console.WriteLine("line {0}:{1} at {2}", line, charPositionInLine, msg);
        }
    }
}
