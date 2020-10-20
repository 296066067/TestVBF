
// Generated from Vbf.g4 by ANTLR 4.8


#include "VbfListener.h"
#include "VbfVisitor.h"

#include "VbfParser.h"


using namespace antlrcpp;
using namespace antlrcpptest;
using namespace antlr4;

VbfParser::VbfParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

VbfParser::~VbfParser() {
  delete _interpreter;
}

std::string VbfParser::getGrammarFileName() const {
  return "Vbf.g4";
}

const std::vector<std::string>& VbfParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& VbfParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- DatabaseContext ------------------------------------------------------------------

VbfParser::DatabaseContext::DatabaseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

VbfParser::VersionSectionContext* VbfParser::DatabaseContext::versionSection() {
  return getRuleContext<VbfParser::VersionSectionContext>(0);
}

VbfParser::HeaderSectionContext* VbfParser::DatabaseContext::headerSection() {
  return getRuleContext<VbfParser::HeaderSectionContext>(0);
}


size_t VbfParser::DatabaseContext::getRuleIndex() const {
  return VbfParser::RuleDatabase;
}

void VbfParser::DatabaseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VbfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDatabase(this);
}

void VbfParser::DatabaseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VbfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDatabase(this);
}


antlrcpp::Any VbfParser::DatabaseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VbfVisitor*>(visitor))
    return parserVisitor->visitDatabase(this);
  else
    return visitor->visitChildren(this);
}

VbfParser::DatabaseContext* VbfParser::database() {
  DatabaseContext *_localctx = _tracker.createInstance<DatabaseContext>(_ctx, getState());
  enterRule(_localctx, 0, VbfParser::RuleDatabase);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(26);
    versionSection();
    setState(27);
    headerSection();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VersionSectionContext ------------------------------------------------------------------

VbfParser::VersionSectionContext::VersionSectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* VbfParser::VersionSectionContext::Reals() {
  return getToken(VbfParser::Reals, 0);
}


size_t VbfParser::VersionSectionContext::getRuleIndex() const {
  return VbfParser::RuleVersionSection;
}

void VbfParser::VersionSectionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VbfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVersionSection(this);
}

void VbfParser::VersionSectionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VbfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVersionSection(this);
}


antlrcpp::Any VbfParser::VersionSectionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VbfVisitor*>(visitor))
    return parserVisitor->visitVersionSection(this);
  else
    return visitor->visitChildren(this);
}

VbfParser::VersionSectionContext* VbfParser::versionSection() {
  VersionSectionContext *_localctx = _tracker.createInstance<VersionSectionContext>(_ctx, getState());
  enterRule(_localctx, 2, VbfParser::RuleVersionSection);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(29);
    match(VbfParser::T__0);
    setState(30);
    match(VbfParser::T__1);
    setState(31);
    match(VbfParser::Reals);
    setState(32);
    match(VbfParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- HeaderSectionContext ------------------------------------------------------------------

VbfParser::HeaderSectionContext::HeaderSectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

VbfParser::SwPartNumberContext* VbfParser::HeaderSectionContext::swPartNumber() {
  return getRuleContext<VbfParser::SwPartNumberContext>(0);
}

VbfParser::SwPartTypeContext* VbfParser::HeaderSectionContext::swPartType() {
  return getRuleContext<VbfParser::SwPartTypeContext>(0);
}

VbfParser::EcuAddressContext* VbfParser::HeaderSectionContext::ecuAddress() {
  return getRuleContext<VbfParser::EcuAddressContext>(0);
}

VbfParser::FrameFormatContext* VbfParser::HeaderSectionContext::frameFormat() {
  return getRuleContext<VbfParser::FrameFormatContext>(0);
}

VbfParser::FileChecksumContext* VbfParser::HeaderSectionContext::fileChecksum() {
  return getRuleContext<VbfParser::FileChecksumContext>(0);
}

VbfParser::DescriptionContext* VbfParser::HeaderSectionContext::description() {
  return getRuleContext<VbfParser::DescriptionContext>(0);
}

VbfParser::DataFormatIdentifierContext* VbfParser::HeaderSectionContext::dataFormatIdentifier() {
  return getRuleContext<VbfParser::DataFormatIdentifierContext>(0);
}

VbfParser::EraseContext* VbfParser::HeaderSectionContext::erase() {
  return getRuleContext<VbfParser::EraseContext>(0);
}

VbfParser::OmitContext* VbfParser::HeaderSectionContext::omit() {
  return getRuleContext<VbfParser::OmitContext>(0);
}

VbfParser::CallContext* VbfParser::HeaderSectionContext::call() {
  return getRuleContext<VbfParser::CallContext>(0);
}


size_t VbfParser::HeaderSectionContext::getRuleIndex() const {
  return VbfParser::RuleHeaderSection;
}

void VbfParser::HeaderSectionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VbfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterHeaderSection(this);
}

void VbfParser::HeaderSectionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VbfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitHeaderSection(this);
}


antlrcpp::Any VbfParser::HeaderSectionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VbfVisitor*>(visitor))
    return parserVisitor->visitHeaderSection(this);
  else
    return visitor->visitChildren(this);
}

VbfParser::HeaderSectionContext* VbfParser::headerSection() {
  HeaderSectionContext *_localctx = _tracker.createInstance<HeaderSectionContext>(_ctx, getState());
  enterRule(_localctx, 4, VbfParser::RuleHeaderSection);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(34);
    match(VbfParser::T__3);
    setState(35);
    match(VbfParser::T__4);
    setState(37);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == VbfParser::T__6) {
      setState(36);
      description();
    }
    setState(39);
    swPartNumber();
    setState(40);
    swPartType();
    setState(42);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == VbfParser::T__18) {
      setState(41);
      dataFormatIdentifier();
    }
    setState(44);
    ecuAddress();
    setState(45);
    frameFormat();
    setState(47);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == VbfParser::T__23) {
      setState(46);
      erase();
    }
    setState(50);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == VbfParser::T__24) {
      setState(49);
      omit();
    }
    setState(53);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == VbfParser::T__25) {
      setState(52);
      call();
    }
    setState(55);
    fileChecksum();
    setState(56);
    match(VbfParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DescriptionContext ------------------------------------------------------------------

VbfParser::DescriptionContext::DescriptionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> VbfParser::DescriptionContext::String() {
  return getTokens(VbfParser::String);
}

tree::TerminalNode* VbfParser::DescriptionContext::String(size_t i) {
  return getToken(VbfParser::String, i);
}


size_t VbfParser::DescriptionContext::getRuleIndex() const {
  return VbfParser::RuleDescription;
}

void VbfParser::DescriptionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VbfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDescription(this);
}

void VbfParser::DescriptionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VbfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDescription(this);
}


antlrcpp::Any VbfParser::DescriptionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VbfVisitor*>(visitor))
    return parserVisitor->visitDescription(this);
  else
    return visitor->visitChildren(this);
}

VbfParser::DescriptionContext* VbfParser::description() {
  DescriptionContext *_localctx = _tracker.createInstance<DescriptionContext>(_ctx, getState());
  enterRule(_localctx, 6, VbfParser::RuleDescription);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(58);
    match(VbfParser::T__6);
    setState(59);
    match(VbfParser::T__1);
    setState(60);
    match(VbfParser::T__4);
    setState(61);
    match(VbfParser::String);
    setState(66);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == VbfParser::T__7) {
      setState(62);
      match(VbfParser::T__7);
      setState(63);
      match(VbfParser::String);
      setState(68);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(69);
    match(VbfParser::T__5);
    setState(70);
    match(VbfParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SwPartNumberContext ------------------------------------------------------------------

VbfParser::SwPartNumberContext::SwPartNumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> VbfParser::SwPartNumberContext::String() {
  return getTokens(VbfParser::String);
}

tree::TerminalNode* VbfParser::SwPartNumberContext::String(size_t i) {
  return getToken(VbfParser::String, i);
}


size_t VbfParser::SwPartNumberContext::getRuleIndex() const {
  return VbfParser::RuleSwPartNumber;
}

void VbfParser::SwPartNumberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VbfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwPartNumber(this);
}

void VbfParser::SwPartNumberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VbfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwPartNumber(this);
}


antlrcpp::Any VbfParser::SwPartNumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VbfVisitor*>(visitor))
    return parserVisitor->visitSwPartNumber(this);
  else
    return visitor->visitChildren(this);
}

VbfParser::SwPartNumberContext* VbfParser::swPartNumber() {
  SwPartNumberContext *_localctx = _tracker.createInstance<SwPartNumberContext>(_ctx, getState());
  enterRule(_localctx, 8, VbfParser::RuleSwPartNumber);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(72);
    match(VbfParser::T__8);
    setState(73);
    match(VbfParser::T__1);
    setState(80);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case VbfParser::String: {
        setState(74);
        match(VbfParser::String);
        break;
      }

      case VbfParser::T__4: {
        setState(75);
        match(VbfParser::T__4);
        setState(76);
        match(VbfParser::String);
        setState(77);
        match(VbfParser::T__7);
        setState(78);
        match(VbfParser::String);
        setState(79);
        match(VbfParser::T__5);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(82);
    match(VbfParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SwPartTypeContext ------------------------------------------------------------------

VbfParser::SwPartTypeContext::SwPartTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t VbfParser::SwPartTypeContext::getRuleIndex() const {
  return VbfParser::RuleSwPartType;
}

void VbfParser::SwPartTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VbfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwPartType(this);
}

void VbfParser::SwPartTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VbfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwPartType(this);
}


antlrcpp::Any VbfParser::SwPartTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VbfVisitor*>(visitor))
    return parserVisitor->visitSwPartType(this);
  else
    return visitor->visitChildren(this);
}

VbfParser::SwPartTypeContext* VbfParser::swPartType() {
  SwPartTypeContext *_localctx = _tracker.createInstance<SwPartTypeContext>(_ctx, getState());
  enterRule(_localctx, 10, VbfParser::RuleSwPartType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(84);
    match(VbfParser::T__9);
    setState(85);
    match(VbfParser::T__1);
    setState(86);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << VbfParser::T__10)
      | (1ULL << VbfParser::T__11)
      | (1ULL << VbfParser::T__12)
      | (1ULL << VbfParser::T__13)
      | (1ULL << VbfParser::T__14)
      | (1ULL << VbfParser::T__15)
      | (1ULL << VbfParser::T__16)
      | (1ULL << VbfParser::T__17))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(87);
    match(VbfParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DataFormatIdentifierContext ------------------------------------------------------------------

VbfParser::DataFormatIdentifierContext::DataFormatIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* VbfParser::DataFormatIdentifierContext::Hexadecimal() {
  return getToken(VbfParser::Hexadecimal, 0);
}

tree::TerminalNode* VbfParser::DataFormatIdentifierContext::Binary() {
  return getToken(VbfParser::Binary, 0);
}

tree::TerminalNode* VbfParser::DataFormatIdentifierContext::Decimal() {
  return getToken(VbfParser::Decimal, 0);
}


size_t VbfParser::DataFormatIdentifierContext::getRuleIndex() const {
  return VbfParser::RuleDataFormatIdentifier;
}

void VbfParser::DataFormatIdentifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VbfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDataFormatIdentifier(this);
}

void VbfParser::DataFormatIdentifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VbfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDataFormatIdentifier(this);
}


antlrcpp::Any VbfParser::DataFormatIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VbfVisitor*>(visitor))
    return parserVisitor->visitDataFormatIdentifier(this);
  else
    return visitor->visitChildren(this);
}

VbfParser::DataFormatIdentifierContext* VbfParser::dataFormatIdentifier() {
  DataFormatIdentifierContext *_localctx = _tracker.createInstance<DataFormatIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 12, VbfParser::RuleDataFormatIdentifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(89);
    match(VbfParser::T__18);
    setState(90);
    match(VbfParser::T__1);
    setState(91);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << VbfParser::Hexadecimal)
      | (1ULL << VbfParser::Binary)
      | (1ULL << VbfParser::Decimal))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(92);
    match(VbfParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EcuAddressContext ------------------------------------------------------------------

VbfParser::EcuAddressContext::EcuAddressContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> VbfParser::EcuAddressContext::Hexadecimal() {
  return getTokens(VbfParser::Hexadecimal);
}

tree::TerminalNode* VbfParser::EcuAddressContext::Hexadecimal(size_t i) {
  return getToken(VbfParser::Hexadecimal, i);
}


size_t VbfParser::EcuAddressContext::getRuleIndex() const {
  return VbfParser::RuleEcuAddress;
}

void VbfParser::EcuAddressContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VbfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEcuAddress(this);
}

void VbfParser::EcuAddressContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VbfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEcuAddress(this);
}


antlrcpp::Any VbfParser::EcuAddressContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VbfVisitor*>(visitor))
    return parserVisitor->visitEcuAddress(this);
  else
    return visitor->visitChildren(this);
}

VbfParser::EcuAddressContext* VbfParser::ecuAddress() {
  EcuAddressContext *_localctx = _tracker.createInstance<EcuAddressContext>(_ctx, getState());
  enterRule(_localctx, 14, VbfParser::RuleEcuAddress);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(94);
    match(VbfParser::T__19);
    setState(95);
    match(VbfParser::T__1);
    setState(104);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case VbfParser::Hexadecimal: {
        setState(96);
        match(VbfParser::Hexadecimal);
        break;
      }

      case VbfParser::T__4: {
        setState(97);
        match(VbfParser::T__4);

        setState(98);
        match(VbfParser::Hexadecimal);
        setState(99);
        match(VbfParser::T__7);

        setState(100);
        match(VbfParser::Hexadecimal);
        setState(101);
        match(VbfParser::T__7);

        setState(102);
        match(VbfParser::Hexadecimal);
        setState(103);
        match(VbfParser::T__5);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(106);
    match(VbfParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FrameFormatContext ------------------------------------------------------------------

VbfParser::FrameFormatContext::FrameFormatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t VbfParser::FrameFormatContext::getRuleIndex() const {
  return VbfParser::RuleFrameFormat;
}

void VbfParser::FrameFormatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VbfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFrameFormat(this);
}

void VbfParser::FrameFormatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VbfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFrameFormat(this);
}


antlrcpp::Any VbfParser::FrameFormatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VbfVisitor*>(visitor))
    return parserVisitor->visitFrameFormat(this);
  else
    return visitor->visitChildren(this);
}

VbfParser::FrameFormatContext* VbfParser::frameFormat() {
  FrameFormatContext *_localctx = _tracker.createInstance<FrameFormatContext>(_ctx, getState());
  enterRule(_localctx, 16, VbfParser::RuleFrameFormat);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(108);
    match(VbfParser::T__20);
    setState(109);
    match(VbfParser::T__1);
    setState(110);
    _la = _input->LA(1);
    if (!(_la == VbfParser::T__21

    || _la == VbfParser::T__22)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(111);
    match(VbfParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EraseContext ------------------------------------------------------------------

VbfParser::EraseContext::EraseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> VbfParser::EraseContext::Hexadecimal() {
  return getTokens(VbfParser::Hexadecimal);
}

tree::TerminalNode* VbfParser::EraseContext::Hexadecimal(size_t i) {
  return getToken(VbfParser::Hexadecimal, i);
}


size_t VbfParser::EraseContext::getRuleIndex() const {
  return VbfParser::RuleErase;
}

void VbfParser::EraseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VbfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterErase(this);
}

void VbfParser::EraseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VbfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitErase(this);
}


antlrcpp::Any VbfParser::EraseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VbfVisitor*>(visitor))
    return parserVisitor->visitErase(this);
  else
    return visitor->visitChildren(this);
}

VbfParser::EraseContext* VbfParser::erase() {
  EraseContext *_localctx = _tracker.createInstance<EraseContext>(_ctx, getState());
  enterRule(_localctx, 18, VbfParser::RuleErase);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(113);
    match(VbfParser::T__23);
    setState(114);
    match(VbfParser::T__1);
    setState(115);
    match(VbfParser::T__4);

    setState(116);
    match(VbfParser::T__4);

    setState(117);
    match(VbfParser::Hexadecimal);
    setState(118);
    match(VbfParser::T__7);

    setState(119);
    match(VbfParser::Hexadecimal);
    setState(120);
    match(VbfParser::T__5);
    setState(130);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == VbfParser::T__7) {
      setState(122);
      match(VbfParser::T__7);
      setState(123);
      match(VbfParser::T__4);

      setState(124);
      match(VbfParser::Hexadecimal);
      setState(125);
      match(VbfParser::T__7);

      setState(126);
      match(VbfParser::Hexadecimal);
      setState(127);
      match(VbfParser::T__5);
      setState(132);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(133);
    match(VbfParser::T__5);
    setState(134);
    match(VbfParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OmitContext ------------------------------------------------------------------

VbfParser::OmitContext::OmitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> VbfParser::OmitContext::Hexadecimal() {
  return getTokens(VbfParser::Hexadecimal);
}

tree::TerminalNode* VbfParser::OmitContext::Hexadecimal(size_t i) {
  return getToken(VbfParser::Hexadecimal, i);
}


size_t VbfParser::OmitContext::getRuleIndex() const {
  return VbfParser::RuleOmit;
}

void VbfParser::OmitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VbfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOmit(this);
}

void VbfParser::OmitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VbfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOmit(this);
}


antlrcpp::Any VbfParser::OmitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VbfVisitor*>(visitor))
    return parserVisitor->visitOmit(this);
  else
    return visitor->visitChildren(this);
}

VbfParser::OmitContext* VbfParser::omit() {
  OmitContext *_localctx = _tracker.createInstance<OmitContext>(_ctx, getState());
  enterRule(_localctx, 20, VbfParser::RuleOmit);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(136);
    match(VbfParser::T__24);
    setState(137);
    match(VbfParser::T__1);
    setState(138);
    match(VbfParser::T__4);

    setState(139);
    match(VbfParser::T__4);

    setState(140);
    match(VbfParser::Hexadecimal);
    setState(141);
    match(VbfParser::T__7);

    setState(142);
    match(VbfParser::Hexadecimal);
    setState(143);
    match(VbfParser::T__5);
    setState(153);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == VbfParser::T__7) {
      setState(145);
      match(VbfParser::T__7);
      setState(146);
      match(VbfParser::T__4);

      setState(147);
      match(VbfParser::Hexadecimal);
      setState(148);
      match(VbfParser::T__7);

      setState(149);
      match(VbfParser::Hexadecimal);
      setState(150);
      match(VbfParser::T__5);
      setState(155);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(156);
    match(VbfParser::T__5);
    setState(157);
    match(VbfParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CallContext ------------------------------------------------------------------

VbfParser::CallContext::CallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* VbfParser::CallContext::Hexadecimal() {
  return getToken(VbfParser::Hexadecimal, 0);
}


size_t VbfParser::CallContext::getRuleIndex() const {
  return VbfParser::RuleCall;
}

void VbfParser::CallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VbfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCall(this);
}

void VbfParser::CallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VbfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCall(this);
}


antlrcpp::Any VbfParser::CallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VbfVisitor*>(visitor))
    return parserVisitor->visitCall(this);
  else
    return visitor->visitChildren(this);
}

VbfParser::CallContext* VbfParser::call() {
  CallContext *_localctx = _tracker.createInstance<CallContext>(_ctx, getState());
  enterRule(_localctx, 22, VbfParser::RuleCall);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(159);
    match(VbfParser::T__25);
    setState(160);
    match(VbfParser::T__1);

    setState(161);
    match(VbfParser::Hexadecimal);
    setState(162);
    match(VbfParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FileChecksumContext ------------------------------------------------------------------

VbfParser::FileChecksumContext::FileChecksumContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* VbfParser::FileChecksumContext::Hexadecimal() {
  return getToken(VbfParser::Hexadecimal, 0);
}


size_t VbfParser::FileChecksumContext::getRuleIndex() const {
  return VbfParser::RuleFileChecksum;
}

void VbfParser::FileChecksumContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VbfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFileChecksum(this);
}

void VbfParser::FileChecksumContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VbfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFileChecksum(this);
}


antlrcpp::Any VbfParser::FileChecksumContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VbfVisitor*>(visitor))
    return parserVisitor->visitFileChecksum(this);
  else
    return visitor->visitChildren(this);
}

VbfParser::FileChecksumContext* VbfParser::fileChecksum() {
  FileChecksumContext *_localctx = _tracker.createInstance<FileChecksumContext>(_ctx, getState());
  enterRule(_localctx, 24, VbfParser::RuleFileChecksum);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(164);
    match(VbfParser::T__26);
    setState(165);
    match(VbfParser::T__1);

    setState(166);
    match(VbfParser::Hexadecimal);
    setState(167);
    match(VbfParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> VbfParser::_decisionToDFA;
atn::PredictionContextCache VbfParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN VbfParser::_atn;
std::vector<uint16_t> VbfParser::_serializedATN;

std::vector<std::string> VbfParser::_ruleNames = {
  "database", "versionSection", "headerSection", "description", "swPartNumber", 
  "swPartType", "dataFormatIdentifier", "ecuAddress", "frameFormat", "erase", 
  "omit", "call", "fileChecksum"
};

std::vector<std::string> VbfParser::_literalNames = {
  "", "'vbf_version'", "'='", "';'", "'header'", "'{'", "'}'", "'description'", 
  "','", "'sw_part_number'", "'sw_part_type'", "'CARCFG'", "'CUSTOM'", "'DATA'", 
  "'EXE'", "'GBL'", "'SBL'", "'SIGCFG'", "'TEST'", "'data_format_identifier'", 
  "'ecu_address'", "'frame_format'", "'CAN_STANDARD'", "'CAN_EXTENDED'", 
  "'erase'", "'omit'", "'call'", "'file_checksum'"
};

std::vector<std::string> VbfParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "String", "Digit", "Letter", "Hexadecimal", 
  "Binary", "Decimal", "Reals", "Whitespace", "CPlusStyleComment", "CStyleComment"
};

dfa::Vocabulary VbfParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> VbfParser::_tokenNames;

VbfParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x27, 0xac, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x28, 0xa, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x2d, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x5, 0x4, 0x32, 0xa, 0x4, 0x3, 0x4, 0x5, 0x4, 0x35, 0xa, 0x4, 0x3, 
    0x4, 0x5, 0x4, 0x38, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x43, 0xa, 
    0x5, 0xc, 0x5, 0xe, 0x5, 0x46, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x5, 0x6, 0x53, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x6b, 0xa, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x7, 0xb, 0x83, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x86, 0xb, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0x9a, 0xa, 0xc, 0xc, 
    0xc, 0xe, 0xc, 0x9d, 0xb, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x2, 0x2, 0xf, 0x2, 0x4, 0x6, 0x8, 0xa, 
    0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x2, 0x5, 0x3, 0x2, 0xd, 
    0x14, 0x3, 0x2, 0x21, 0x23, 0x3, 0x2, 0x18, 0x19, 0x2, 0xa8, 0x2, 0x1c, 
    0x3, 0x2, 0x2, 0x2, 0x4, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x6, 0x24, 0x3, 0x2, 
    0x2, 0x2, 0x8, 0x3c, 0x3, 0x2, 0x2, 0x2, 0xa, 0x4a, 0x3, 0x2, 0x2, 0x2, 
    0xc, 0x56, 0x3, 0x2, 0x2, 0x2, 0xe, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x10, 
    0x60, 0x3, 0x2, 0x2, 0x2, 0x12, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x14, 0x73, 
    0x3, 0x2, 0x2, 0x2, 0x16, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x18, 0xa1, 0x3, 
    0x2, 0x2, 0x2, 0x1a, 0xa6, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1d, 0x5, 0x4, 
    0x3, 0x2, 0x1d, 0x1e, 0x5, 0x6, 0x4, 0x2, 0x1e, 0x3, 0x3, 0x2, 0x2, 
    0x2, 0x1f, 0x20, 0x7, 0x3, 0x2, 0x2, 0x20, 0x21, 0x7, 0x4, 0x2, 0x2, 
    0x21, 0x22, 0x7, 0x24, 0x2, 0x2, 0x22, 0x23, 0x7, 0x5, 0x2, 0x2, 0x23, 
    0x5, 0x3, 0x2, 0x2, 0x2, 0x24, 0x25, 0x7, 0x6, 0x2, 0x2, 0x25, 0x27, 
    0x7, 0x7, 0x2, 0x2, 0x26, 0x28, 0x5, 0x8, 0x5, 0x2, 0x27, 0x26, 0x3, 
    0x2, 0x2, 0x2, 0x27, 0x28, 0x3, 0x2, 0x2, 0x2, 0x28, 0x29, 0x3, 0x2, 
    0x2, 0x2, 0x29, 0x2a, 0x5, 0xa, 0x6, 0x2, 0x2a, 0x2c, 0x5, 0xc, 0x7, 
    0x2, 0x2b, 0x2d, 0x5, 0xe, 0x8, 0x2, 0x2c, 0x2b, 0x3, 0x2, 0x2, 0x2, 
    0x2c, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x2e, 
    0x2f, 0x5, 0x10, 0x9, 0x2, 0x2f, 0x31, 0x5, 0x12, 0xa, 0x2, 0x30, 0x32, 
    0x5, 0x14, 0xb, 0x2, 0x31, 0x30, 0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 0x3, 
    0x2, 0x2, 0x2, 0x32, 0x34, 0x3, 0x2, 0x2, 0x2, 0x33, 0x35, 0x5, 0x16, 
    0xc, 0x2, 0x34, 0x33, 0x3, 0x2, 0x2, 0x2, 0x34, 0x35, 0x3, 0x2, 0x2, 
    0x2, 0x35, 0x37, 0x3, 0x2, 0x2, 0x2, 0x36, 0x38, 0x5, 0x18, 0xd, 0x2, 
    0x37, 0x36, 0x3, 0x2, 0x2, 0x2, 0x37, 0x38, 0x3, 0x2, 0x2, 0x2, 0x38, 
    0x39, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3a, 0x5, 0x1a, 0xe, 0x2, 0x3a, 0x3b, 
    0x7, 0x8, 0x2, 0x2, 0x3b, 0x7, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3d, 0x7, 
    0x9, 0x2, 0x2, 0x3d, 0x3e, 0x7, 0x4, 0x2, 0x2, 0x3e, 0x3f, 0x7, 0x7, 
    0x2, 0x2, 0x3f, 0x44, 0x7, 0x1e, 0x2, 0x2, 0x40, 0x41, 0x7, 0xa, 0x2, 
    0x2, 0x41, 0x43, 0x7, 0x1e, 0x2, 0x2, 0x42, 0x40, 0x3, 0x2, 0x2, 0x2, 
    0x43, 0x46, 0x3, 0x2, 0x2, 0x2, 0x44, 0x42, 0x3, 0x2, 0x2, 0x2, 0x44, 
    0x45, 0x3, 0x2, 0x2, 0x2, 0x45, 0x47, 0x3, 0x2, 0x2, 0x2, 0x46, 0x44, 
    0x3, 0x2, 0x2, 0x2, 0x47, 0x48, 0x7, 0x8, 0x2, 0x2, 0x48, 0x49, 0x7, 
    0x5, 0x2, 0x2, 0x49, 0x9, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4b, 0x7, 0xb, 
    0x2, 0x2, 0x4b, 0x52, 0x7, 0x4, 0x2, 0x2, 0x4c, 0x53, 0x7, 0x1e, 0x2, 
    0x2, 0x4d, 0x4e, 0x7, 0x7, 0x2, 0x2, 0x4e, 0x4f, 0x7, 0x1e, 0x2, 0x2, 
    0x4f, 0x50, 0x7, 0xa, 0x2, 0x2, 0x50, 0x51, 0x7, 0x1e, 0x2, 0x2, 0x51, 
    0x53, 0x7, 0x8, 0x2, 0x2, 0x52, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x52, 0x4d, 
    0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0x3, 0x2, 0x2, 0x2, 0x54, 0x55, 0x7, 
    0x5, 0x2, 0x2, 0x55, 0xb, 0x3, 0x2, 0x2, 0x2, 0x56, 0x57, 0x7, 0xc, 
    0x2, 0x2, 0x57, 0x58, 0x7, 0x4, 0x2, 0x2, 0x58, 0x59, 0x9, 0x2, 0x2, 
    0x2, 0x59, 0x5a, 0x7, 0x5, 0x2, 0x2, 0x5a, 0xd, 0x3, 0x2, 0x2, 0x2, 
    0x5b, 0x5c, 0x7, 0x15, 0x2, 0x2, 0x5c, 0x5d, 0x7, 0x4, 0x2, 0x2, 0x5d, 
    0x5e, 0x9, 0x3, 0x2, 0x2, 0x5e, 0x5f, 0x7, 0x5, 0x2, 0x2, 0x5f, 0xf, 
    0x3, 0x2, 0x2, 0x2, 0x60, 0x61, 0x7, 0x16, 0x2, 0x2, 0x61, 0x6a, 0x7, 
    0x4, 0x2, 0x2, 0x62, 0x6b, 0x7, 0x21, 0x2, 0x2, 0x63, 0x64, 0x7, 0x7, 
    0x2, 0x2, 0x64, 0x65, 0x7, 0x21, 0x2, 0x2, 0x65, 0x66, 0x7, 0xa, 0x2, 
    0x2, 0x66, 0x67, 0x7, 0x21, 0x2, 0x2, 0x67, 0x68, 0x7, 0xa, 0x2, 0x2, 
    0x68, 0x69, 0x7, 0x21, 0x2, 0x2, 0x69, 0x6b, 0x7, 0x8, 0x2, 0x2, 0x6a, 
    0x62, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x63, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6c, 
    0x3, 0x2, 0x2, 0x2, 0x6c, 0x6d, 0x7, 0x5, 0x2, 0x2, 0x6d, 0x11, 0x3, 
    0x2, 0x2, 0x2, 0x6e, 0x6f, 0x7, 0x17, 0x2, 0x2, 0x6f, 0x70, 0x7, 0x4, 
    0x2, 0x2, 0x70, 0x71, 0x9, 0x4, 0x2, 0x2, 0x71, 0x72, 0x7, 0x5, 0x2, 
    0x2, 0x72, 0x13, 0x3, 0x2, 0x2, 0x2, 0x73, 0x74, 0x7, 0x1a, 0x2, 0x2, 
    0x74, 0x75, 0x7, 0x4, 0x2, 0x2, 0x75, 0x76, 0x7, 0x7, 0x2, 0x2, 0x76, 
    0x77, 0x7, 0x7, 0x2, 0x2, 0x77, 0x78, 0x7, 0x21, 0x2, 0x2, 0x78, 0x79, 
    0x7, 0xa, 0x2, 0x2, 0x79, 0x7a, 0x7, 0x21, 0x2, 0x2, 0x7a, 0x7b, 0x7, 
    0x8, 0x2, 0x2, 0x7b, 0x84, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7d, 0x7, 0xa, 
    0x2, 0x2, 0x7d, 0x7e, 0x7, 0x7, 0x2, 0x2, 0x7e, 0x7f, 0x7, 0x21, 0x2, 
    0x2, 0x7f, 0x80, 0x7, 0xa, 0x2, 0x2, 0x80, 0x81, 0x7, 0x21, 0x2, 0x2, 
    0x81, 0x83, 0x7, 0x8, 0x2, 0x2, 0x82, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x83, 
    0x86, 0x3, 0x2, 0x2, 0x2, 0x84, 0x82, 0x3, 0x2, 0x2, 0x2, 0x84, 0x85, 
    0x3, 0x2, 0x2, 0x2, 0x85, 0x87, 0x3, 0x2, 0x2, 0x2, 0x86, 0x84, 0x3, 
    0x2, 0x2, 0x2, 0x87, 0x88, 0x7, 0x8, 0x2, 0x2, 0x88, 0x89, 0x7, 0x5, 
    0x2, 0x2, 0x89, 0x15, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8b, 0x7, 0x1b, 0x2, 
    0x2, 0x8b, 0x8c, 0x7, 0x4, 0x2, 0x2, 0x8c, 0x8d, 0x7, 0x7, 0x2, 0x2, 
    0x8d, 0x8e, 0x7, 0x7, 0x2, 0x2, 0x8e, 0x8f, 0x7, 0x21, 0x2, 0x2, 0x8f, 
    0x90, 0x7, 0xa, 0x2, 0x2, 0x90, 0x91, 0x7, 0x21, 0x2, 0x2, 0x91, 0x92, 
    0x7, 0x8, 0x2, 0x2, 0x92, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x93, 0x94, 0x7, 
    0xa, 0x2, 0x2, 0x94, 0x95, 0x7, 0x7, 0x2, 0x2, 0x95, 0x96, 0x7, 0x21, 
    0x2, 0x2, 0x96, 0x97, 0x7, 0xa, 0x2, 0x2, 0x97, 0x98, 0x7, 0x21, 0x2, 
    0x2, 0x98, 0x9a, 0x7, 0x8, 0x2, 0x2, 0x99, 0x93, 0x3, 0x2, 0x2, 0x2, 
    0x9a, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x99, 0x3, 0x2, 0x2, 0x2, 0x9b, 
    0x9c, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9e, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x9b, 
    0x3, 0x2, 0x2, 0x2, 0x9e, 0x9f, 0x7, 0x8, 0x2, 0x2, 0x9f, 0xa0, 0x7, 
    0x5, 0x2, 0x2, 0xa0, 0x17, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa2, 0x7, 0x1c, 
    0x2, 0x2, 0xa2, 0xa3, 0x7, 0x4, 0x2, 0x2, 0xa3, 0xa4, 0x7, 0x21, 0x2, 
    0x2, 0xa4, 0xa5, 0x7, 0x5, 0x2, 0x2, 0xa5, 0x19, 0x3, 0x2, 0x2, 0x2, 
    0xa6, 0xa7, 0x7, 0x1d, 0x2, 0x2, 0xa7, 0xa8, 0x7, 0x4, 0x2, 0x2, 0xa8, 
    0xa9, 0x7, 0x21, 0x2, 0x2, 0xa9, 0xaa, 0x7, 0x5, 0x2, 0x2, 0xaa, 0x1b, 
    0x3, 0x2, 0x2, 0x2, 0xc, 0x27, 0x2c, 0x31, 0x34, 0x37, 0x44, 0x52, 0x6a, 
    0x84, 0x9b, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

VbfParser::Initializer VbfParser::_init;
