//------------------------------------------------------------------------------
//! @file ParameterSymbols.h
//! @brief Contains parameter-related symbol definitions
//
// File is under the MIT license; see LICENSE for details
//------------------------------------------------------------------------------
#pragma once

#include "slang/symbols/Symbol.h"

namespace slang {

class ParameterSymbolBase {
public:
    const Symbol& symbol;

    bool isLocalParam() const { return isLocal; }
    bool isPortParam() const { return isPort; }
    bool isBodyParam() const { return !isPortParam(); }
    bool hasDefault() const;

protected:
    ParameterSymbolBase(const Symbol& symbol, bool isLocal, bool isPort) :
        symbol(symbol), isLocal(isLocal), isPort(isPort) {}

private:
    bool isLocal = false;
    bool isPort = false;
};

struct ParameterDeclarationSyntax;

/// Represents a parameter value.
class ParameterSymbol : public ValueSymbol, public ParameterSymbolBase {
public:
    ParameterSymbol(string_view name, SourceLocation loc, bool isLocal, bool isPort);

    static void fromSyntax(const Scope& scope, const ParameterDeclarationSyntax& syntax,
                           bool isLocal, bool isPort, SmallVector<ParameterSymbol*>& results);

    static bool isKind(SymbolKind kind) { return kind == SymbolKind::Parameter; }

    ParameterSymbol& clone(Compilation& compilation) const;

    const ConstantValue& getValue() const;
    void setValue(ConstantValue value);

    void serializeTo(ASTSerializer& serializer) const;

private:
    const ConstantValue* overriden = nullptr;
};

struct TypeParameterDeclarationSyntax;

class TypeParameterSymbol : public Symbol, public ParameterSymbolBase {
public:
    DeclaredType targetType;

    TypeParameterSymbol(string_view name, SourceLocation loc, bool isLocal, bool isPort);

    static void fromSyntax(const Scope& scope, const TypeParameterDeclarationSyntax& syntax,
                           bool isLocal, bool isPort, SmallVector<TypeParameterSymbol*>& results);

    static bool isKind(SymbolKind kind) { return kind == SymbolKind::TypeParameter; }

    TypeParameterSymbol& clone(Compilation& compilation) const;

    const Type& getTypeAlias() const;

    void serializeTo(ASTSerializer& serializer) const;

private:
    mutable const Type* typeAlias = nullptr;
};

} // namespace slang