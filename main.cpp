
#define USE_CPP11
#define USE_CPP14
#define USE_CPP17

//#define MSVC_NOT_SUPPORTED_ENABLED

#ifdef USE_CPP17

//C++17 Language Features
//-------------------------------------------------------//
//-------------------------------------------------------//

//template argument deduction for class templates
#include "C++17/Language/TemplateArgumentDeduction.h"
//declaring non - type template parameters with auto
#include "C++17/Language/NontypeTemplateParametersWithAuto.h"
//folding expressions
#include "C++17/Language/FoldingExpressions.h"
//new rules for auto deduction from braced - init - list
#include "C++17/Language/AutoDeductionFromBraceInitList.h"
//constexpr lambda
#include "C++17/Language/ConstExprLambda.h"
//lambda capture this by value
#include "C++17/Language/LambdaCaptureByValue.h"
//inline variables
#include "C++17/Language/InlineVariables.h"
//nested namespaces
#include "C++17/Language/NestedNamespaces.h"
//structured bindings
#include "C++17/Language/StructuredBindings.h"
//selection statements with initializer
#include "C++17/Language/SelectionStatementsWithInitialiser.h"
//constexpr if
#include "C++17/Language/ConstExprIf.h"
//utf - 8 character literals
#include "C++17/Language/UTF8CharacterLiterals.h"
//direct - list - initialization of enums
#include "C++17/Language/InitialisationOfEnums.h"
//-------------------------------------------------------//
//-------------------------------------------------------//

//C++17 Library Features
//-------------------------------------------------------//
//-------------------------------------------------------//

//std::variant
#include "C++17/Library/Variant.h"
//std::optional
#include "C++17/Library/Optional.h"
//std::any
#include "C++17/Library/Any.h"
//std::string_view
#include "C++17/Library/StringView.h"
//std::invoke
#include "C++17/Library/Invoke.h"
//std::apply
#include "C++17/Library/Apply.h"
//splicing for maps and sets
#include "C++17/Library/MapSetSplicing.h"
//-------------------------------------------------------//
//-------------------------------------------------------//

#endif

#ifdef USE_CPP14
//C++14 Language Features
//-------------------------------------------------------//
//-------------------------------------------------------//
//binary literals
#include "C++14/Language/BinaryLiterals.h"
//generic lambda expressions
#include "C++14/Language/GenericLambda.h"
//lambda capture initializers
#include "C++14/Language/LambdaCaptureInit.h"
//return type deduction
#include "C++14/Language/ReturnTypeDeduction.h"
//decltype(auto)
#include "C++14/Language/DeclTypeAuto.h"
//relaxing constraints on constexpr functions
#include "C++14/Language/ConstExprRelaxed.h"
//variable templates
#include "C++14/Language/VariableTemplates.h"
//-------------------------------------------------------//
//-------------------------------------------------------//

//C++14 Library Features
//-------------------------------------------------------//
//-------------------------------------------------------//
//user - defined literals for standard library types
#include "C++14/Library/UserLiterals.h"
//compile - time integer sequences
#include "C++14/Library/CompileTimeIntegers.h"
//std::make_unique
#include "C++14/Library/MakeUnique.h"
//-------------------------------------------------------//
//-------------------------------------------------------//
#endif

#ifdef USE_CPP11

//C++11 Language Features
//-------------------------------------------------------//
//-------------------------------------------------------//
//move semantics
#include "C++11/Language/MoveSemantics.h"
//variadic templates
#include "C++11/Language/VariadicTemplates.h"
//rvalue references
#include "C++11/Language/RValueReferences.h"
//initializer lists
#include "C++11/Language/InitialiserLists.h"
//static assertions
#include "C++11/Language/StaticAssertions.h"
//auto
#include "C++11/Language/auto.h"
//lambda expressions
#include "C++11/Language/LambdaExpressions.h"
//decltype
#include "C++11/Language/DeclTypes.h"
//template aliases
#include "C++11/Language/TemplateAliases.h"
//nullptr
#include "C++11/Language/Nullptr.h"
//strongly - typed enums
#include "C++11/Language/StronglyTypedEnums.h"
//attributes
#include "C++11/Language/Attributes.h"
//constexpr
#include "C++11/Language/ConstExpr.h"
//delegating constructors
#include "C++11/Language/DelegatingConstructors.h"
//user - defined literals
#include "C++11/Language/UserDefinedLiterals.h"
//explicit virtual overrides
#include "C++11/Language/ExplicitVirtualOverrides.h"
//final specifier
#include "C++11/Language/FinalSpecifier.h"
//default functions
#include "C++11/Language/DefaultFunctions.h"
//deleted functions
#include "C++11/Language/DeletedFunctions.h"
//range - based for loops
#include "C++11/Language/RangeBasedLoops.h"
//special member functions for move semantics
#include "C++11/Language/SpecialMoveSemanticFunctions.h"
//converting constructors
#include "C++11/Language/ConvertingConstructors.h"
//explicit conversion functions
#include "C++11/Language/ExplicitConversionFunctions.h"
//inline - namespaces
#include "C++11/Language/InlineNamespaces.h"
//non - static data member initializers
#include "C++11/Language/NonStaticMemberInitialiser.h"
//right angle brackets
#include "C++11/Language/RightAngleBrackets.h"
//-------------------------------------------------------//
//-------------------------------------------------------//

//C++11 Library Features
//-------------------------------------------------------//
//-------------------------------------------------------//
//std::move
#include "C++11/Library/move.h"
//std::forward
#include "C++11/Library/Forward.h"
//std::to_string
#include "C++11/Library/ToString.h"
//type traits
#include "C++11/Library/TypeTraits.h"
//smart pointers
#include "C++11/Library/SmartPointers.h"
//std::chrono
#include "C++11/Library/chrono.h"
//tuples
#include "C++11/Library/tuples.h"
//std::tie
#include "C++11/Library/tie.h"
//std::array
#include "C++11/Library/Array.h"
//unordered containers
#include "C++11/Library/UnorderedContainers.h"
//std::make_shared
#include "C++11/Library/MakeShared.h"
//memory model
#include "C++11/Library/MemoryModel.h"
//-------------------------------------------------------//
//-------------------------------------------------------//
#endif

int main()
{

}