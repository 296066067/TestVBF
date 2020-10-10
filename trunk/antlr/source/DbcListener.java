// Generated from Dbc.g4 by ANTLR 4.8
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link DbcParser}.
 */
public interface DbcListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link DbcParser#database}.
	 * @param ctx the parse tree
	 */
	void enterDatabase(DbcParser.DatabaseContext ctx);
	/**
	 * Exit a parse tree produced by {@link DbcParser#database}.
	 * @param ctx the parse tree
	 */
	void exitDatabase(DbcParser.DatabaseContext ctx);
	/**
	 * Enter a parse tree produced by {@link DbcParser#versionSection}.
	 * @param ctx the parse tree
	 */
	void enterVersionSection(DbcParser.VersionSectionContext ctx);
	/**
	 * Exit a parse tree produced by {@link DbcParser#versionSection}.
	 * @param ctx the parse tree
	 */
	void exitVersionSection(DbcParser.VersionSectionContext ctx);
	/**
	 * Enter a parse tree produced by {@link DbcParser#headerSection}.
	 * @param ctx the parse tree
	 */
	void enterHeaderSection(DbcParser.HeaderSectionContext ctx);
	/**
	 * Exit a parse tree produced by {@link DbcParser#headerSection}.
	 * @param ctx the parse tree
	 */
	void exitHeaderSection(DbcParser.HeaderSectionContext ctx);
	/**
	 * Enter a parse tree produced by {@link DbcParser#description}.
	 * @param ctx the parse tree
	 */
	void enterDescription(DbcParser.DescriptionContext ctx);
	/**
	 * Exit a parse tree produced by {@link DbcParser#description}.
	 * @param ctx the parse tree
	 */
	void exitDescription(DbcParser.DescriptionContext ctx);
	/**
	 * Enter a parse tree produced by {@link DbcParser#swPartNnumber}.
	 * @param ctx the parse tree
	 */
	void enterSwPartNnumber(DbcParser.SwPartNnumberContext ctx);
	/**
	 * Exit a parse tree produced by {@link DbcParser#swPartNnumber}.
	 * @param ctx the parse tree
	 */
	void exitSwPartNnumber(DbcParser.SwPartNnumberContext ctx);
	/**
	 * Enter a parse tree produced by {@link DbcParser#swPartType}.
	 * @param ctx the parse tree
	 */
	void enterSwPartType(DbcParser.SwPartTypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link DbcParser#swPartType}.
	 * @param ctx the parse tree
	 */
	void exitSwPartType(DbcParser.SwPartTypeContext ctx);
	/**
	 * Enter a parse tree produced by {@link DbcParser#dataFormatIdentifier}.
	 * @param ctx the parse tree
	 */
	void enterDataFormatIdentifier(DbcParser.DataFormatIdentifierContext ctx);
	/**
	 * Exit a parse tree produced by {@link DbcParser#dataFormatIdentifier}.
	 * @param ctx the parse tree
	 */
	void exitDataFormatIdentifier(DbcParser.DataFormatIdentifierContext ctx);
	/**
	 * Enter a parse tree produced by {@link DbcParser#ecuAddress}.
	 * @param ctx the parse tree
	 */
	void enterEcuAddress(DbcParser.EcuAddressContext ctx);
	/**
	 * Exit a parse tree produced by {@link DbcParser#ecuAddress}.
	 * @param ctx the parse tree
	 */
	void exitEcuAddress(DbcParser.EcuAddressContext ctx);
	/**
	 * Enter a parse tree produced by {@link DbcParser#frameFormat}.
	 * @param ctx the parse tree
	 */
	void enterFrameFormat(DbcParser.FrameFormatContext ctx);
	/**
	 * Exit a parse tree produced by {@link DbcParser#frameFormat}.
	 * @param ctx the parse tree
	 */
	void exitFrameFormat(DbcParser.FrameFormatContext ctx);
	/**
	 * Enter a parse tree produced by {@link DbcParser#erase}.
	 * @param ctx the parse tree
	 */
	void enterErase(DbcParser.EraseContext ctx);
	/**
	 * Exit a parse tree produced by {@link DbcParser#erase}.
	 * @param ctx the parse tree
	 */
	void exitErase(DbcParser.EraseContext ctx);
	/**
	 * Enter a parse tree produced by {@link DbcParser#omit}.
	 * @param ctx the parse tree
	 */
	void enterOmit(DbcParser.OmitContext ctx);
	/**
	 * Exit a parse tree produced by {@link DbcParser#omit}.
	 * @param ctx the parse tree
	 */
	void exitOmit(DbcParser.OmitContext ctx);
	/**
	 * Enter a parse tree produced by {@link DbcParser#call}.
	 * @param ctx the parse tree
	 */
	void enterCall(DbcParser.CallContext ctx);
	/**
	 * Exit a parse tree produced by {@link DbcParser#call}.
	 * @param ctx the parse tree
	 */
	void exitCall(DbcParser.CallContext ctx);
	/**
	 * Enter a parse tree produced by {@link DbcParser#fileChecksum}.
	 * @param ctx the parse tree
	 */
	void enterFileChecksum(DbcParser.FileChecksumContext ctx);
	/**
	 * Exit a parse tree produced by {@link DbcParser#fileChecksum}.
	 * @param ctx the parse tree
	 */
	void exitFileChecksum(DbcParser.FileChecksumContext ctx);
}