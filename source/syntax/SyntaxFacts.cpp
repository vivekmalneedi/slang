//------------------------------------------------------------------------------
// SyntaxFacts.cpp
// Various syntax-related utility methods
//
// File is under the MIT license; see LICENSE for details
//------------------------------------------------------------------------------
#include "slang/syntax/SyntaxFacts.h"

#include "slang/syntax/AllSyntax.h"

namespace slang {

string_view SyntaxFacts::getSimpleTypeName(const DataTypeSyntax& syntax) {
    if (syntax.kind == SyntaxKind::NamedType) {
        auto& namedType = syntax.as<NamedTypeSyntax>();
        if (namedType.name->kind == SyntaxKind::IdentifierName)
            return namedType.name->as<IdentifierNameSyntax>().identifier.valueText();
    }
    return "";
}

// clang-format off
SyntaxKind SyntaxFacts::getUnaryPrefixExpression(TokenKind kind) {
    switch (kind) {
        case TokenKind::Plus: return SyntaxKind::UnaryPlusExpression;
        case TokenKind::Minus: return SyntaxKind::UnaryMinusExpression;
        case TokenKind::And: return SyntaxKind::UnaryBitwiseAndExpression;
        case TokenKind::TildeAnd: return SyntaxKind::UnaryBitwiseNandExpression;
        case TokenKind::Or: return SyntaxKind::UnaryBitwiseOrExpression;
        case TokenKind::TildeOr: return SyntaxKind::UnaryBitwiseNorExpression;
        case TokenKind::Xor: return SyntaxKind::UnaryBitwiseXorExpression;
        case TokenKind::XorTilde:
        case TokenKind::TildeXor:
            return SyntaxKind::UnaryBitwiseXnorExpression;
        case TokenKind::DoublePlus: return SyntaxKind::UnaryPreincrementExpression;
        case TokenKind::DoubleMinus: return SyntaxKind::UnaryPredecrementExpression;
        case TokenKind::Tilde: return SyntaxKind::UnaryBitwiseNotExpression;
        case TokenKind::Exclamation: return SyntaxKind::UnaryLogicalNotExpression;
        case TokenKind::DoubleHash: return SyntaxKind::UnarySequenceDelayExpression;
        case TokenKind::At: return SyntaxKind::UnarySequenceEventExpression;
        case TokenKind::AcceptOnKeyword: return SyntaxKind::AcceptOnPropertyExpression;
        case TokenKind::RejectOnKeyword: return SyntaxKind::RejectOnPropertyExpression;
        case TokenKind::SyncAcceptOnKeyword: return SyntaxKind::SyncAcceptOnPropertyExpression;
        case TokenKind::SyncRejectOnKeyword: return SyntaxKind::SyncRejectOnPropertyExpression;
        case TokenKind::NotKeyword: return SyntaxKind::UnaryNotPropertyExpression;
        case TokenKind::NextTimeKeyword: return SyntaxKind::NextTimePropertyExpression;
        case TokenKind::SNextTimeKeyword: return SyntaxKind::SNextTimePropertyExpression;
        case TokenKind::AlwaysKeyword: return SyntaxKind::AlwaysPropertyExpression;
        case TokenKind::SAlwaysKeyword: return SyntaxKind::SAlwaysPropertyExpression;
        case TokenKind::EventuallyKeyword: return SyntaxKind::EventuallyPropertyExpression;
        case TokenKind::SEventuallyKeyword: return SyntaxKind::SEventuallyPropertyExpression;
        default:
            return SyntaxKind::Unknown;
    }
}

SyntaxKind SyntaxFacts::getUnaryPostfixExpression(TokenKind kind) {
    switch (kind) {
        case TokenKind::DoublePlus: return SyntaxKind::PostincrementExpression;
        case TokenKind::DoubleMinus: return SyntaxKind::PostdecrementExpression;
        default: return SyntaxKind::Unknown;
    }
}

SyntaxKind SyntaxFacts::getLiteralExpression(TokenKind kind) {
    switch (kind) {
        case TokenKind::StringLiteral: return SyntaxKind::StringLiteralExpression;
        case TokenKind::IntegerLiteral: return SyntaxKind::IntegerLiteralExpression;
        case TokenKind::UnbasedUnsizedLiteral: return SyntaxKind::UnbasedUnsizedLiteralExpression;
        case TokenKind::RealLiteral: return SyntaxKind::RealLiteralExpression;
        case TokenKind::TimeLiteral: return SyntaxKind::TimeLiteralExpression;
        case TokenKind::NullKeyword: return SyntaxKind::NullLiteralExpression;
        case TokenKind::Dollar: return SyntaxKind::WildcardLiteralExpression;
        case TokenKind::OneStep: return SyntaxKind::OneStepLiteralExpression;
        default: return SyntaxKind::Unknown;
    }
}

SyntaxKind SyntaxFacts::getBinaryExpression(TokenKind kind) {
    switch (kind) {
        case TokenKind::Plus: return SyntaxKind::AddExpression;
        case TokenKind::Minus: return SyntaxKind::SubtractExpression;
        case TokenKind::Star: return SyntaxKind::MultiplyExpression;
        case TokenKind::Slash: return SyntaxKind::DivideExpression;
        case TokenKind::Percent: return SyntaxKind::ModExpression;
        case TokenKind::DoubleStar: return SyntaxKind::PowerExpression;
        case TokenKind::DoubleEquals: return SyntaxKind::EqualityExpression;
        case TokenKind::ExclamationEquals: return SyntaxKind::InequalityExpression;
        case TokenKind::TripleEquals: return SyntaxKind::CaseEqualityExpression;
        case TokenKind::ExclamationDoubleEquals: return SyntaxKind::CaseInequalityExpression;
        case TokenKind::DoubleEqualsQuestion: return SyntaxKind::WildcardEqualityExpression;
        case TokenKind::ExclamationEqualsQuestion: return SyntaxKind::WildcardInequalityExpression;
        case TokenKind::DoubleAnd: return SyntaxKind::LogicalAndExpression;
        case TokenKind::DoubleOr: return SyntaxKind::LogicalOrExpression;
        case TokenKind::MinusArrow: return SyntaxKind::LogicalImplicationExpression;
        case TokenKind::LessThanMinusArrow: return SyntaxKind::LogicalEquivalenceExpression;
        case TokenKind::LessThan: return SyntaxKind::LessThanExpression;
        case TokenKind::LessThanEquals: return SyntaxKind::LessThanEqualExpression;
        case TokenKind::GreaterThan: return SyntaxKind::GreaterThanExpression;
        case TokenKind::GreaterThanEquals: return SyntaxKind::GreaterThanEqualExpression;
        case TokenKind::And: return SyntaxKind::BinaryAndExpression;
        case TokenKind::Or: return SyntaxKind::BinaryOrExpression;
        case TokenKind::Xor: return SyntaxKind::BinaryXorExpression;
        case TokenKind::XorTilde: return SyntaxKind::BinaryXnorExpression;
        case TokenKind::TildeXor: return SyntaxKind::BinaryXnorExpression;
        case TokenKind::RightShift: return SyntaxKind::LogicalShiftRightExpression;
        case TokenKind::TripleRightShift: return SyntaxKind::ArithmeticShiftRightExpression;
        case TokenKind::LeftShift: return SyntaxKind::LogicalShiftLeftExpression;
        case TokenKind::TripleLeftShift: return SyntaxKind::ArithmeticShiftLeftExpression;
        case TokenKind::InsideKeyword: return SyntaxKind::InsideExpression;
        case TokenKind::Equals: return SyntaxKind::AssignmentExpression;
        case TokenKind::PlusEqual: return SyntaxKind::AddAssignmentExpression;
        case TokenKind::MinusEqual: return SyntaxKind::SubtractAssignmentExpression;
        case TokenKind::StarEqual: return SyntaxKind::MultiplyAssignmentExpression;
        case TokenKind::SlashEqual: return SyntaxKind::DivideAssignmentExpression;
        case TokenKind::PercentEqual: return SyntaxKind::ModAssignmentExpression;
        case TokenKind::AndEqual: return SyntaxKind::AndAssignmentExpression;
        case TokenKind::OrEqual: return SyntaxKind::OrAssignmentExpression;
        case TokenKind::XorEqual: return SyntaxKind::XorAssignmentExpression;
        case TokenKind::LeftShiftEqual: return SyntaxKind::LogicalLeftShiftAssignmentExpression;
        case TokenKind::TripleLeftShiftEqual: return SyntaxKind::ArithmeticLeftShiftAssignmentExpression;
        case TokenKind::RightShiftEqual: return SyntaxKind::LogicalRightShiftAssignmentExpression;
        case TokenKind::TripleRightShiftEqual: return SyntaxKind::ArithmeticRightShiftAssignmentExpression;
        case TokenKind::OrKeyword: return SyntaxKind::OrSequenceExpression;
        case TokenKind::AndKeyword: return SyntaxKind::AndSequenceExpression;
        case TokenKind::IntersectKeyword: return SyntaxKind::IntersectSequenceExpression;
        case TokenKind::WithinKeyword: return SyntaxKind::WithinSequenceExpression;
        case TokenKind::ThroughoutKeyword: return SyntaxKind::ThroughoutSequenceExpression;
        case TokenKind::IffKeyword: return SyntaxKind::IffPropertyExpression;
        case TokenKind::UntilKeyword: return SyntaxKind::UntilPropertyExpression;
        case TokenKind::SUntilKeyword: return SyntaxKind::SUntilPropertyExpression;
        case TokenKind::UntilWithKeyword: return SyntaxKind::UntilWithPropertyExpression;
        case TokenKind::SUntilWithKeyword: return SyntaxKind::SUntilWithPropertyExpression;
        case TokenKind::ImpliesKeyword: return SyntaxKind::ImpliesPropertyExpression;
        case TokenKind::OrMinusArrow: return SyntaxKind::OverlappedImplicationPropertyExpression;
        case TokenKind::OrEqualsArrow: return SyntaxKind::NonOverlappedImplicationPropertyExpression;
        case TokenKind::HashMinusHash: return SyntaxKind::OverlappedFollowedByPropertyExpression;
        case TokenKind::HashEqualsHash: return SyntaxKind::NonOverlappedFollowedByPropertyExpression;
        case TokenKind::DoubleHash: return SyntaxKind::BinarySequenceDelayExpression;
        default: return SyntaxKind::Unknown;
    }
}

SyntaxKind SyntaxFacts::getKeywordNameExpression(TokenKind kind) {
    switch (kind) {
        case TokenKind::UnitSystemName: return SyntaxKind::UnitScope;
        case TokenKind::RootSystemName: return SyntaxKind::RootScope;
        case TokenKind::LocalKeyword: return SyntaxKind::LocalScope;
        case TokenKind::ThisKeyword: return SyntaxKind::ThisHandle;
        case TokenKind::SuperKeyword: return SyntaxKind::SuperHandle;
        case TokenKind::UniqueKeyword: return SyntaxKind::ArrayUniqueMethod;
        case TokenKind::AndKeyword: return SyntaxKind::ArrayAndMethod;
        case TokenKind::OrKeyword: return SyntaxKind::ArrayOrMethod;
        case TokenKind::XorKeyword: return SyntaxKind::ArrayXorMethod;
        case TokenKind::NewKeyword: return SyntaxKind::ConstructorName;
        default: return SyntaxKind::Unknown;
    }
}

bool SyntaxFacts::isSpecialMethodName(SyntaxKind kind) {
    switch (kind) {
        case SyntaxKind::ArrayUniqueMethod:
        case SyntaxKind::ArrayAndMethod:
        case SyntaxKind::ArrayOrMethod:
        case SyntaxKind::ArrayXorMethod:
        case SyntaxKind::ConstructorName:
            return true;
            default:
                return false;
        }
    }

int SyntaxFacts::getPrecedence(SyntaxKind kind) {
    switch (kind) {
        case SyntaxKind::AlwaysPropertyExpression:
        case SyntaxKind::SAlwaysPropertyExpression:
        case SyntaxKind::EventuallyPropertyExpression:
        case SyntaxKind::SEventuallyPropertyExpression:
        case SyntaxKind::AcceptOnPropertyExpression:
        case SyntaxKind::RejectOnPropertyExpression:
        case SyntaxKind::SyncAcceptOnPropertyExpression:
        case SyntaxKind::SyncRejectOnPropertyExpression:
            return 1;
        case SyntaxKind::OverlappedImplicationPropertyExpression:
        case SyntaxKind::NonOverlappedImplicationPropertyExpression:
        case SyntaxKind::OverlappedFollowedByPropertyExpression:
        case SyntaxKind::NonOverlappedFollowedByPropertyExpression:
            return 2;
        case SyntaxKind::UntilPropertyExpression:
        case SyntaxKind::SUntilPropertyExpression:
        case SyntaxKind::UntilWithPropertyExpression:
        case SyntaxKind::SUntilWithPropertyExpression:
        case SyntaxKind::ImpliesPropertyExpression:
            return 3;
        case SyntaxKind::IffPropertyExpression:
            return 3;
        case SyntaxKind::OrSequenceExpression:
            return 4;
        case SyntaxKind::AndSequenceExpression:
            return 5;
        case SyntaxKind::UnaryNotPropertyExpression:
        case SyntaxKind::NextTimePropertyExpression:
        case SyntaxKind::SNextTimePropertyExpression:
            return 6;
        case SyntaxKind::IntersectSequenceExpression:
            return 7;
        case SyntaxKind::WithinSequenceExpression:
            return 8;
        case SyntaxKind::ThroughoutSequenceExpression:
            return 9;
        case SyntaxKind::BinarySequenceDelayExpression:
        case SyntaxKind::UnarySequenceDelayExpression:
        case SyntaxKind::UnarySequenceEventExpression:
            return 10;
        case SyntaxKind::AssignmentExpression:
        case SyntaxKind::AddAssignmentExpression:
        case SyntaxKind::SubtractAssignmentExpression:
        case SyntaxKind::MultiplyAssignmentExpression:
        case SyntaxKind::DivideAssignmentExpression:
        case SyntaxKind::ModAssignmentExpression:
        case SyntaxKind::AndAssignmentExpression:
        case SyntaxKind::OrAssignmentExpression:
        case SyntaxKind::XorAssignmentExpression:
        case SyntaxKind::LogicalLeftShiftAssignmentExpression:
        case SyntaxKind::LogicalRightShiftAssignmentExpression:
        case SyntaxKind::ArithmeticLeftShiftAssignmentExpression:
        case SyntaxKind::ArithmeticRightShiftAssignmentExpression:
        case SyntaxKind::NonblockingAssignmentExpression:
            return 11;
        case SyntaxKind::LogicalImplicationExpression:
        case SyntaxKind::LogicalEquivalenceExpression:
            return 12;
        case SyntaxKind::LogicalOrExpression:
            return 13;
        case SyntaxKind::LogicalAndExpression:
            return 14;
        case SyntaxKind::BinaryOrExpression:
            return 15;
        case SyntaxKind::BinaryXorExpression:
        case SyntaxKind::BinaryXnorExpression:
            return 16;
        case SyntaxKind::BinaryAndExpression:
            return 17;
        case SyntaxKind::EqualityExpression:
        case SyntaxKind::InequalityExpression:
        case SyntaxKind::CaseEqualityExpression:
        case SyntaxKind::CaseInequalityExpression:
        case SyntaxKind::WildcardEqualityExpression:
        case SyntaxKind::WildcardInequalityExpression:
            return 18;
        case SyntaxKind::LessThanExpression:
        case SyntaxKind::LessThanEqualExpression:
        case SyntaxKind::GreaterThanExpression:
        case SyntaxKind::GreaterThanEqualExpression:
        case SyntaxKind::InsideExpression:
            return 19;
        case SyntaxKind::LogicalShiftLeftExpression:
        case SyntaxKind::LogicalShiftRightExpression:
        case SyntaxKind::ArithmeticShiftLeftExpression:
        case SyntaxKind::ArithmeticShiftRightExpression:
            return 20;
        case SyntaxKind::AddExpression:
        case SyntaxKind::SubtractExpression:
            return 21;
        case SyntaxKind::MultiplyExpression:
        case SyntaxKind::DivideExpression:
        case SyntaxKind::ModExpression:
            return 22;
        case SyntaxKind::PowerExpression:
            return 23;
        case SyntaxKind::UnaryPlusExpression:
        case SyntaxKind::UnaryMinusExpression:
        case SyntaxKind::UnaryLogicalNotExpression:
        case SyntaxKind::UnaryBitwiseNotExpression:
        case SyntaxKind::UnaryBitwiseAndExpression:
        case SyntaxKind::UnaryBitwiseNandExpression:
        case SyntaxKind::UnaryBitwiseOrExpression:
        case SyntaxKind::UnaryBitwiseNorExpression:
        case SyntaxKind::UnaryBitwiseXorExpression:
        case SyntaxKind::UnaryBitwiseXnorExpression:
        case SyntaxKind::UnaryPreincrementExpression:
        case SyntaxKind::UnaryPredecrementExpression:
            return 24;
        default:
            return 0;
    }
}

bool SyntaxFacts::isRightAssociative(SyntaxKind kind) {
    switch (kind) {
        case SyntaxKind::LogicalImplicationExpression:
        case SyntaxKind::LogicalEquivalenceExpression:
        case SyntaxKind::ThroughoutSequenceExpression:
        case SyntaxKind::IffPropertyExpression:
        case SyntaxKind::UntilPropertyExpression:
        case SyntaxKind::SUntilPropertyExpression:
        case SyntaxKind::UntilWithPropertyExpression:
        case SyntaxKind::SUntilWithPropertyExpression:
        case SyntaxKind::ImpliesPropertyExpression:
        case SyntaxKind::OverlappedImplicationPropertyExpression:
        case SyntaxKind::NonOverlappedImplicationPropertyExpression:
        case SyntaxKind::OverlappedFollowedByPropertyExpression:
        case SyntaxKind::NonOverlappedFollowedByPropertyExpression:
            return true;
        default:
            return false;
    }
}

bool SyntaxFacts::isPossibleDataType(TokenKind kind) {
    switch (kind) {
        case TokenKind::BitKeyword:
        case TokenKind::LogicKeyword:
        case TokenKind::RegKeyword:
        case TokenKind::ByteKeyword:
        case TokenKind::ShortIntKeyword:
        case TokenKind::IntKeyword:
        case TokenKind::LongIntKeyword:
        case TokenKind::IntegerKeyword:
        case TokenKind::TimeKeyword:
        case TokenKind::ShortRealKeyword:
        case TokenKind::RealKeyword:
        case TokenKind::RealTimeKeyword:
        case TokenKind::StringKeyword:
        case TokenKind::ConstKeyword:
        case TokenKind::SignedKeyword:
        case TokenKind::UnsignedKeyword:
        case TokenKind::StructKeyword:
        case TokenKind::UnionKeyword:
        case TokenKind::EnumKeyword:
        case TokenKind::CHandleKeyword:
        case TokenKind::VirtualKeyword:
        case TokenKind::EventKeyword:
        case TokenKind::TypeKeyword:
        case TokenKind::VoidKeyword:
        case TokenKind::Identifier:
        case TokenKind::UnitSystemName:
        case TokenKind::OpenBracket:
            return true;
        default:
            return false;
    }
}

bool SyntaxFacts::isPossibleExpression(TokenKind kind) {
    switch (kind) {
        case TokenKind::TaggedKeyword:
        case TokenKind::StringLiteral:
        case TokenKind::IntegerLiteral:
        case TokenKind::UnbasedUnsizedLiteral:
        case TokenKind::IntegerBase:
        case TokenKind::RealLiteral:
        case TokenKind::TimeLiteral:
        case TokenKind::NullKeyword:
        case TokenKind::Dollar:
        case TokenKind::LocalKeyword:
        case TokenKind::OpenParenthesis:
        case TokenKind::OpenBrace:
        case TokenKind::OpenBracket:
        case TokenKind::UnitSystemName:
        case TokenKind::ThisKeyword:
        case TokenKind::SuperKeyword:
        case TokenKind::Identifier:
        case TokenKind::SystemIdentifier:
        case TokenKind::RootSystemName:
        case TokenKind::Hash:
        case TokenKind::DoubleHash:
        case TokenKind::At:
        case TokenKind::TypeKeyword:
        case TokenKind::ApostropheOpenBrace:
        case TokenKind::FirstMatchKeyword:
        case TokenKind::StrongKeyword:
        case TokenKind::WeakKeyword:
        case TokenKind::IfKeyword:
        case TokenKind::CaseKeyword:
            // expressions can't actually start with these, but we'll allow it
            // to provide good error handling
        case TokenKind::DoubleColon:
        case TokenKind::Question:
        case TokenKind::MatchesKeyword:
        case TokenKind::TripleAnd:
        case TokenKind::InsideKeyword:
        case TokenKind::DistKeyword:
            return true;
        default:
            break;
    }

    if (isPossibleDataType(kind))
        return true;

    SyntaxKind opKind = getUnaryPrefixExpression(kind);
    if (opKind != SyntaxKind::Unknown)
        return true;

    opKind = getBinaryExpression(kind);
    if (opKind != SyntaxKind::Unknown)
        return true;

    return false;
}

bool SyntaxFacts::isPossibleStatement(TokenKind kind) {
    switch (kind) {
        case TokenKind::Identifier:
        case TokenKind::SystemIdentifier:
        case TokenKind::ThisKeyword:
        case TokenKind::SuperKeyword:
        case TokenKind::UnitSystemName:
        case TokenKind::RootSystemName:
        case TokenKind::OpenBrace:
        case TokenKind::ApostropheOpenBrace:
        case TokenKind::AssignKeyword:
        case TokenKind::DeassignKeyword:
        case TokenKind::ForceKeyword:
        case TokenKind::ReleaseKeyword:
        case TokenKind::UniqueKeyword:
        case TokenKind::Unique0Keyword:
        case TokenKind::PriorityKeyword:
        case TokenKind::CaseKeyword:
        case TokenKind::CaseXKeyword:
        case TokenKind::CaseZKeyword:
        case TokenKind::IfKeyword:
        case TokenKind::DoublePlus:
        case TokenKind::DoubleMinus:
        case TokenKind::VoidKeyword:
        case TokenKind::TypeKeyword:
        case TokenKind::DisableKeyword:
        case TokenKind::MinusArrow:
        case TokenKind::OrMinusDoubleArrow:
        case TokenKind::ForeverKeyword:
        case TokenKind::RepeatKeyword:
        case TokenKind::WhileKeyword:
        case TokenKind::ForKeyword:
        case TokenKind::DoKeyword:
        case TokenKind::ForeachKeyword:
        case TokenKind::ReturnKeyword:
        case TokenKind::BreakKeyword:
        case TokenKind::ContinueKeyword:
        case TokenKind::ForkKeyword:
        case TokenKind::Hash:
        case TokenKind::DoubleHash:
        case TokenKind::At:
        case TokenKind::BeginKeyword:
        case TokenKind::WaitKeyword:
        case TokenKind::WaitOrderKeyword:
        case TokenKind::AssertKeyword:
        case TokenKind::AssumeKeyword:
        case TokenKind::CoverKeyword:
        case TokenKind::RestrictKeyword:
        case TokenKind::RandSequenceKeyword:
        case TokenKind::RandCaseKeyword:
        case TokenKind::ExpectKeyword:
        case TokenKind::OpenParenthesisStar:
        case TokenKind::Semicolon:
            return true;
        default:
            return false;
    }
}

SyntaxKind SyntaxFacts::getIntegerType(TokenKind kind) {
    switch (kind) {
        case TokenKind::BitKeyword: return SyntaxKind::BitType;
        case TokenKind::LogicKeyword: return SyntaxKind::LogicType;
        case TokenKind::RegKeyword: return SyntaxKind::RegType;
        case TokenKind::ByteKeyword: return SyntaxKind::ByteType;
        case TokenKind::ShortIntKeyword: return SyntaxKind::ShortIntType;
        case TokenKind::IntKeyword: return SyntaxKind::IntType;
        case TokenKind::LongIntKeyword: return SyntaxKind::LongIntType;
        case TokenKind::IntegerKeyword: return SyntaxKind::IntegerType;
        case TokenKind::TimeKeyword: return SyntaxKind::TimeType;
        default: return SyntaxKind::Unknown;
    }
}

SyntaxKind SyntaxFacts::getKeywordType(TokenKind kind) {
    switch (kind) {
        case TokenKind::ShortRealKeyword: return SyntaxKind::ShortRealType;
        case TokenKind::RealKeyword: return SyntaxKind::RealType;
        case TokenKind::RealTimeKeyword: return SyntaxKind::RealTimeType;
        case TokenKind::StringKeyword: return SyntaxKind::StringType;
        case TokenKind::CHandleKeyword: return SyntaxKind::CHandleType;
        case TokenKind::EventKeyword: return SyntaxKind::EventType;
        case TokenKind::VoidKeyword: return SyntaxKind::VoidType;
        default: return SyntaxKind::Unknown;
    }
}

SyntaxKind SyntaxFacts::getProceduralBlockKind(TokenKind kind) {
    switch (kind) {
        case TokenKind::InitialKeyword: return SyntaxKind::InitialBlock;
        case TokenKind::FinalKeyword: return SyntaxKind::FinalBlock;
        case TokenKind::AlwaysKeyword: return SyntaxKind::AlwaysBlock;
        case TokenKind::AlwaysCombKeyword: return SyntaxKind::AlwaysCombBlock;
        case TokenKind::AlwaysFFKeyword: return SyntaxKind::AlwaysFFBlock;
        case TokenKind::AlwaysLatchKeyword: return SyntaxKind::AlwaysLatchBlock;
        default: return SyntaxKind::Unknown;
    }
}

SyntaxKind SyntaxFacts::getModuleHeaderKind(TokenKind kind) {
    switch (kind) {
        case TokenKind::ModuleKeyword: return SyntaxKind::ModuleHeader;
        case TokenKind::MacromoduleKeyword: return SyntaxKind::ModuleHeader;
        case TokenKind::ProgramKeyword: return SyntaxKind::ProgramHeader;
        case TokenKind::InterfaceKeyword: return SyntaxKind::InterfaceHeader;
        case TokenKind::PackageKeyword: return SyntaxKind::PackageHeader;
        default: return SyntaxKind::Unknown;
    }
}

SyntaxKind SyntaxFacts::getModuleDeclarationKind(TokenKind kind) {
    switch (kind) {
        case TokenKind::ModuleKeyword: return SyntaxKind::ModuleDeclaration;
        case TokenKind::MacromoduleKeyword: return SyntaxKind::ModuleDeclaration;
        case TokenKind::ProgramKeyword: return SyntaxKind::ProgramDeclaration;
        case TokenKind::InterfaceKeyword: return SyntaxKind::InterfaceDeclaration;
        case TokenKind::PackageKeyword: return SyntaxKind::PackageDeclaration;
        default: return SyntaxKind::Unknown;
    }
}

TokenKind SyntaxFacts::getModuleEndKind(TokenKind kind) {
    switch (kind) {
        case TokenKind::ModuleKeyword: return TokenKind::EndModuleKeyword;
        case TokenKind::MacromoduleKeyword: return TokenKind::EndModuleKeyword;
        case TokenKind::ProgramKeyword: return TokenKind::EndProgramKeyword;
        case TokenKind::InterfaceKeyword: return TokenKind::EndInterfaceKeyword;
        case TokenKind::PackageKeyword: return TokenKind::EndPackageKeyword;
        default: return TokenKind::Unknown;
    }
}

TokenKind SyntaxFacts::getDelimCloseKind(TokenKind kind) {
    switch (kind) {
        case TokenKind::OpenParenthesis: return TokenKind::CloseParenthesis;
        case TokenKind::OpenBrace: return TokenKind::CloseBrace;
        case TokenKind::OpenBracket: return TokenKind::CloseBracket;
        case TokenKind::ApostropheOpenBrace: return TokenKind::CloseBrace;
        case TokenKind::OpenParenthesisStar: return TokenKind::StarCloseParenthesis;
        default: return TokenKind::Unknown;
    }
}

TokenKind SyntaxFacts::getSkipToKind(TokenKind kind) {
    switch (kind) {
        case TokenKind::OpenParenthesis: return TokenKind::CloseParenthesis;
        case TokenKind::OpenBrace: return TokenKind::CloseBrace;
        case TokenKind::OpenBracket: return TokenKind::CloseBracket;
        case TokenKind::ApostropheOpenBrace: return TokenKind::CloseBrace;
        case TokenKind::OpenParenthesisStar: return TokenKind::StarCloseParenthesis;
        case TokenKind::BeginKeyword: return TokenKind::EndKeyword;
        case TokenKind::CaseKeyword: return TokenKind::EndCaseKeyword;
        case TokenKind::CheckerKeyword: return TokenKind::EndCheckerKeyword;
        case TokenKind::ClassKeyword: return TokenKind::EndClassKeyword;
        case TokenKind::ClockingKeyword: return TokenKind::EndClockingKeyword;
        case TokenKind::ConfigKeyword: return TokenKind::EndConfigKeyword;
        case TokenKind::ForkKeyword: return TokenKind::JoinKeyword;
        case TokenKind::FunctionKeyword: return TokenKind::EndFunctionKeyword;
        case TokenKind::GenerateKeyword: return TokenKind::EndGenerateKeyword;
        case TokenKind::CoverGroupKeyword: return TokenKind::EndGroupKeyword;
        case TokenKind::InterfaceKeyword: return TokenKind::EndInterfaceKeyword;
        case TokenKind::ModuleKeyword: return TokenKind::EndModuleKeyword;
        case TokenKind::MacromoduleKeyword: return TokenKind::EndModuleKeyword;
        case TokenKind::PackageKeyword: return TokenKind::EndPackageKeyword;
        case TokenKind::PrimitiveKeyword: return TokenKind::EndPrimitiveKeyword;
        case TokenKind::ProgramKeyword: return TokenKind::EndProgramKeyword;
        case TokenKind::PropertyKeyword: return TokenKind::EndPropertyKeyword;
        case TokenKind::SpecifyKeyword: return TokenKind::EndSpecifyKeyword;
        case TokenKind::SequenceKeyword: return TokenKind::EndSequenceKeyword;
        case TokenKind::TableKeyword: return TokenKind::EndTableKeyword;
        case TokenKind::TaskKeyword: return TokenKind::EndTaskKeyword;
        default:
            return TokenKind::Unknown;
    }
}

bool SyntaxFacts::isNetType(TokenKind kind) {
    switch (kind) {
        case TokenKind::Supply0Keyword:
        case TokenKind::Supply1Keyword:
        case TokenKind::TriKeyword:
        case TokenKind::TriAndKeyword:
        case TokenKind::TriOrKeyword:
        case TokenKind::TriRegKeyword:
        case TokenKind::Tri0Keyword:
        case TokenKind::Tri1Keyword:
        case TokenKind::UWireKeyword:
        case TokenKind::WireKeyword:
        case TokenKind::WAndKeyword:
        case TokenKind::WOrKeyword:
            return true;
        default:
            return false;
    }
}

bool SyntaxFacts::isPortDirection(TokenKind kind) {
    switch (kind) {
        case TokenKind::InputKeyword:
        case TokenKind::OutputKeyword:
        case TokenKind::InOutKeyword:
        case TokenKind::RefKeyword:
            return true;
        default:
            return false;
    }
}

bool SyntaxFacts::isPossibleArgument(TokenKind kind) {
    // allow a comma here to handle cases like:  foo(, 3);
    switch (kind) {
        case TokenKind::Dot:
        case TokenKind::Comma:
            return true;
        default:
            return isPossibleExpression(kind);
    }
}

bool SyntaxFacts::isPossibleNonAnsiPort(TokenKind kind) {
    switch (kind) {
        case TokenKind::Dot:
        case TokenKind::Comma:
        case TokenKind::Identifier:
        case TokenKind::OpenBrace:
            return true;
        default:
            return false;
    }
}

bool SyntaxFacts::isPossibleAnsiPort(TokenKind kind) {
    switch (kind) {
        case TokenKind::InterconnectKeyword:
        case TokenKind::InterfaceKeyword:
        case TokenKind::Identifier:
        case TokenKind::Dot:
        case TokenKind::Comma:
        case TokenKind::InputKeyword:
        case TokenKind::OutputKeyword:
        case TokenKind::InOutKeyword:
        case TokenKind::RefKeyword:
        case TokenKind::VarKeyword:
        case TokenKind::OpenParenthesisStar:
            return true;
        default:
            return isNetType(kind) || isPossibleDataType(kind);
    }
}

bool SyntaxFacts::isPossibleModportPort(TokenKind kind) {
    switch (kind) {
        case TokenKind::OpenParenthesisStar:
        case TokenKind::InputKeyword:
        case TokenKind::OutputKeyword:
        case TokenKind::InOutKeyword:
        case TokenKind::RefKeyword:
        case TokenKind::ClockingKeyword:
        case TokenKind::ImportKeyword:
        case TokenKind::ExportKeyword:
        case TokenKind::Comma:
            return true;
        default:
            return false;
    }
}

bool SyntaxFacts::isPossibleFunctionPort(TokenKind kind) {
    switch (kind) {
        case TokenKind::Identifier:
        case TokenKind::Comma:
        case TokenKind::InputKeyword:
        case TokenKind::OutputKeyword:
        case TokenKind::InOutKeyword:
        case TokenKind::RefKeyword:
        case TokenKind::VarKeyword:
        case TokenKind::ConstKeyword:
        case TokenKind::OpenParenthesisStar:
            return true;
        default:
            return isPossibleDataType(kind);
    }
}

bool SyntaxFacts::isComma(TokenKind kind) {
    return kind == TokenKind::Comma;
}

bool SyntaxFacts::isSemicolon(TokenKind kind) {
    return kind == TokenKind::Semicolon;
}

bool SyntaxFacts::isCloseBrace(TokenKind kind) {
    return kind == TokenKind::CloseBrace;
}

bool SyntaxFacts::isIdentifierOrComma(TokenKind kind) {
    return kind == TokenKind::Identifier || kind == TokenKind::Comma;
}

bool SyntaxFacts::isPossibleExpressionOrComma(TokenKind kind) {
    return kind == TokenKind::Comma || isPossibleExpression(kind);
}

bool SyntaxFacts::isPossibleExpressionOrCommaOrDefault(TokenKind kind) {
    return kind == TokenKind::Comma || kind == TokenKind::DefaultKeyword || isPossibleExpression(kind);
}

bool SyntaxFacts::isPossibleExpressionOrTripleAnd(TokenKind kind) {
    return kind == TokenKind::TripleAnd || isPossibleExpression(kind);
}

bool SyntaxFacts::isPossibleForInitializer(TokenKind kind) {
    return kind == TokenKind::Comma || kind == TokenKind::VarKeyword || isPossibleExpression(kind);
}

bool SyntaxFacts::isPossibleOpenRangeElement(TokenKind kind) {
    switch (kind) {
        case TokenKind::OpenBracket:
        case TokenKind::Comma:
            return true;
        default:
            return isPossibleExpression(kind);
    }
}

bool SyntaxFacts::isPossiblePattern(TokenKind kind) {
    switch (kind) {
        case TokenKind::Dot:
        case TokenKind::DotStar:
        case TokenKind::ApostropheOpenBrace:
            return true;
        default:
            return isPossibleExpression(kind);
    }
}

bool SyntaxFacts::isPossibleDelayOrEventControl(TokenKind kind) {
    switch (kind) {
        case TokenKind::Hash:
        case TokenKind::At:
        case TokenKind::RepeatKeyword:
            return true;
        default:
            return false;
    }
}

bool SyntaxFacts::isPossibleGateInstance(TokenKind kind) {
    switch (kind) {
        case TokenKind::Identifier:
        case TokenKind::OpenParenthesis:
        case TokenKind::Comma:
            return true;
        default:
            return false;
    }
}

bool SyntaxFacts::isPossibleParameter(TokenKind kind) {
    switch (kind) {
        case TokenKind::ParameterKeyword:
        case TokenKind::LocalParamKeyword:
        case TokenKind::TypeKeyword:
        case TokenKind::Comma:
            return true;
        default:
            return isPossibleDataType(kind);
    }
}

bool SyntaxFacts::isPossiblePortConnection(TokenKind kind) {
    switch (kind) {
        case TokenKind::OpenParenthesisStar:
        case TokenKind::DotStar:
        case TokenKind::Dot:
        case TokenKind::Comma:
            return true;
        default:
            return isPossibleExpression(kind);
    }
}

bool SyntaxFacts::isPossibleVectorDigit(TokenKind kind) {
    switch (kind) {
        case TokenKind::IntegerLiteral:
        case TokenKind::Question:
        case TokenKind::RealLiteral:
        case TokenKind::Identifier:
            return true;
        default:
            return false;
    }
}

bool SyntaxFacts::isEndKeyword(TokenKind kind) {
    switch (kind) {
        case TokenKind::EndKeyword:
        case TokenKind::EndCaseKeyword:
        case TokenKind::EndCheckerKeyword:
        case TokenKind::EndClassKeyword:
        case TokenKind::EndClockingKeyword:
        case TokenKind::EndConfigKeyword:
        case TokenKind::EndFunctionKeyword:
        case TokenKind::EndGenerateKeyword:
        case TokenKind::EndGroupKeyword:
        case TokenKind::EndInterfaceKeyword:
        case TokenKind::EndModuleKeyword:
        case TokenKind::EndPackageKeyword:
        case TokenKind::EndPrimitiveKeyword:
        case TokenKind::EndProgramKeyword:
        case TokenKind::EndPropertyKeyword:
        case TokenKind::EndSpecifyKeyword:
        case TokenKind::EndSequenceKeyword:
        case TokenKind::EndTableKeyword:
        case TokenKind::EndTaskKeyword:
        case TokenKind::JoinAnyKeyword:
        case TokenKind::JoinKeyword:
        case TokenKind::JoinNoneKeyword:
            return true;
        default:
            return false;
    }
}

bool SyntaxFacts::isOpenDelimOrKeyword(TokenKind kind) {
    return getSkipToKind(kind) != TokenKind::Unknown;
}

bool SyntaxFacts::isCloseDelimOrKeyword(TokenKind kind) {
    switch (kind) {
        case TokenKind::CloseBrace:
        case TokenKind::CloseBracket:
        case TokenKind::CloseParenthesis:
        case TokenKind::StarCloseParenthesis:
            return true;
        default:
            return isEndKeyword(kind);
    }
}

bool SyntaxFacts::isMatchingDelims(TokenKind openKind, TokenKind closeKind) {
    if (getSkipToKind(openKind) == closeKind)
        return true;

    if (openKind == TokenKind::ForkKeyword) {
        switch (closeKind) {
            case TokenKind::JoinKeyword:
            case TokenKind::JoinAnyKeyword:
            case TokenKind::JoinNoneKeyword:
                return true;
            default:
                break;
        }
    }

    return false;
}

bool SyntaxFacts::isDeclarationModifier(TokenKind kind) {
    switch (kind) {
        case TokenKind::ConstKeyword:
        case TokenKind::VarKeyword:
        case TokenKind::StaticKeyword:
        case TokenKind::AutomaticKeyword:
            return true;
        default:
            return false;
    }
}

bool SyntaxFacts::isLifetimeModifier(TokenKind kind) {
    switch (kind) {
        case TokenKind::StaticKeyword:
        case TokenKind::AutomaticKeyword:
            return true;
        default:
            return false;
    }
}

bool SyntaxFacts::isMemberQualifier(TokenKind kind) {
    switch (kind) {
        case TokenKind::ConstKeyword:
        case TokenKind::RandKeyword:
        case TokenKind::RandCKeyword:
        case TokenKind::PureKeyword:
        case TokenKind::VirtualKeyword:
        case TokenKind::ExternKeyword:
        case TokenKind::StaticKeyword:
        case TokenKind::LocalKeyword:
        case TokenKind::ProtectedKeyword:
            return true;
        default:
            return false;
    }
}

bool SyntaxFacts::isDriveStrength(TokenKind kind) {
    switch (kind) {
        case TokenKind::Supply0Keyword:
        case TokenKind::Strong0Keyword:
        case TokenKind::Pull0Keyword:
        case TokenKind::Weak0Keyword:
        case TokenKind::HighZ0Keyword:
        case TokenKind::Supply1Keyword:
        case TokenKind::Strong1Keyword:
        case TokenKind::Pull1Keyword:
        case TokenKind::Weak1Keyword:
        case TokenKind::HighZ1Keyword:
            return true;
        default:
            return false;
    }
}

bool SyntaxFacts::isChargeStrength(TokenKind kind) {
    switch (kind) {
        case TokenKind::SmallKeyword:
        case TokenKind::MediumKeyword:
        case TokenKind::LargeKeyword:
            return true;
        default:
            return false;
    }
}

bool SyntaxFacts::isGateType(TokenKind kind) {
    switch (kind) {
        case TokenKind::CmosKeyword:
        case TokenKind::RcmosKeyword:
        case TokenKind::NmosKeyword:
        case TokenKind::PmosKeyword:
        case TokenKind::RnmosKeyword:
        case TokenKind::RpmosKeyword:
        case TokenKind::BufIf0Keyword:
        case TokenKind::BufIf1Keyword:
        case TokenKind::NotIf0Keyword:
        case TokenKind::NotIf1Keyword:
        case TokenKind::AndKeyword:
        case TokenKind::NandKeyword:
        case TokenKind::OrKeyword:
        case TokenKind::NorKeyword:
        case TokenKind::XorKeyword:
        case TokenKind::XnorKeyword:
        case TokenKind::BufKeyword:
        case TokenKind::NotKeyword:
        case TokenKind::TranIf0Keyword:
        case TokenKind::TranIf1Keyword:
        case TokenKind::RtranIf0Keyword:
        case TokenKind::RtranIf1Keyword:
        case TokenKind::TranKeyword:
        case TokenKind::RtranKeyword:
        case TokenKind::PullDownKeyword:
        case TokenKind::PullUpKeyword:
            return true;
        default:
            return false;
    }
}

bool SyntaxFacts::isEndOfParenList(TokenKind kind) {
    return kind == TokenKind::CloseParenthesis || kind == TokenKind::Semicolon;
}

bool SyntaxFacts::isEndOfBracedList(TokenKind kind) {
    return kind == TokenKind::CloseBrace || kind == TokenKind::Semicolon;
}

bool SyntaxFacts::isEndOfBracketedList(TokenKind kind) {
    return kind == TokenKind::CloseBracket || kind == TokenKind::Semicolon;
}

bool SyntaxFacts::isEndOfCaseItem(TokenKind kind) {
    return kind == TokenKind::Colon || kind == TokenKind::Semicolon;
}

bool SyntaxFacts::isEndOfConditionalPredicate(TokenKind kind) {
    return kind == TokenKind::Question || kind == TokenKind::CloseParenthesis ||
        kind == TokenKind::BeginKeyword || kind == TokenKind::Semicolon;
}

bool SyntaxFacts::isEndOfAttribute(TokenKind kind) {
    switch (kind) {
        case TokenKind::StarCloseParenthesis:
            // these indicate a missing *) somewhere
        case TokenKind::Semicolon:
        case TokenKind::PrimitiveKeyword:
        case TokenKind::ProgramKeyword:
        case TokenKind::InterfaceKeyword:
        case TokenKind::PackageKeyword:
        case TokenKind::CheckerKeyword:
        case TokenKind::GenerateKeyword:
        case TokenKind::ModuleKeyword:
        case TokenKind::ClassKeyword:
            return true;
        default:
            return false;
    }
}

bool SyntaxFacts::isEndOfParameterList(TokenKind kind) {
    return kind == TokenKind::CloseParenthesis || kind == TokenKind::OpenParenthesis || kind == TokenKind::Semicolon;
}

bool SyntaxFacts::isEndOfTransSet(TokenKind kind) {
    switch (kind) {
        case TokenKind::Semicolon:
        case TokenKind::CloseParenthesis:
        case TokenKind::BinsKeyword:
        case TokenKind::IllegalBinsKeyword:
        case TokenKind::IgnoreBinsKeyword:
            return true;
        default:
            return false;
    }
}

bool SyntaxFacts::isNotInType(TokenKind kind) {
    switch (kind) {
        case TokenKind::Semicolon:
        case TokenKind::EndOfFile:
            return true;
        default:
            return isEndKeyword(kind);
    }
}

bool SyntaxFacts::isNotInPortReference(TokenKind kind) {
    return kind == TokenKind::Semicolon || kind == TokenKind::EndOfFile;
}

bool SyntaxFacts::isNotInConcatenationExpr(TokenKind kind) {
    switch (kind) {
        case TokenKind::Semicolon:
        case TokenKind::EndOfFile:
        case TokenKind::IfKeyword:
        case TokenKind::ForeachKeyword:
        case TokenKind::SoftKeyword:
        case TokenKind::UniqueKeyword:
        case TokenKind::DistKeyword:
        case TokenKind::DisableKeyword:
        case TokenKind::MinusArrow:
            return true;
        default:
            return false;
    }
}

bool SyntaxFacts::isPossibleLetPortItem(TokenKind kind) {
    return kind == TokenKind::OpenParenthesisStar || kind == TokenKind::UntypedKeyword || isPossibleDataType(kind);
}

bool SyntaxFacts::isNotInParameterList(TokenKind kind) {
    return kind == TokenKind::OpenParenthesis || kind == TokenKind::Semicolon || kind == TokenKind::EndOfFile;
}

bool SyntaxFacts::isPossiblePropertyPortItem(TokenKind kind) {
    switch (kind) {
        case TokenKind::OpenParenthesisStar:
        case TokenKind::LocalKeyword:
        case TokenKind::PropertyKeyword:
        case TokenKind::SequenceKeyword:
        case TokenKind::Comma:
            return true;
        default:
            return isPossibleDataType(kind);
    }
}

bool SyntaxFacts::isPossibleTransSet(TokenKind kind) {
    switch (kind) {
        case TokenKind::OpenParenthesis:
        case TokenKind::Comma:
        case TokenKind::EqualsArrow:
        case TokenKind::OpenBracket:
            return true;
        default:
            return isPossibleExpression(kind);
    }
}

bool SyntaxFacts::isBeforeOrSemicolon(TokenKind kind) {
    return kind == TokenKind::Semicolon || kind == TokenKind::BeforeKeyword;
}

bool SyntaxFacts::isModifierAllowedAfter(TokenKind mod, TokenKind prev) {
    switch (mod) {
        case TokenKind::ConstKeyword: return false;
        case TokenKind::VarKeyword: return prev == TokenKind::ConstKeyword;
        case TokenKind::StaticKeyword:
        case TokenKind::AutomaticKeyword:
            return prev == TokenKind::VarKeyword || prev == TokenKind::ConstKeyword;
        default:
            return false;
    }
}

// clang-format on

} // namespace slang
