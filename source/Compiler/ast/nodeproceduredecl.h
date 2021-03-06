#ifndef NODEPROCEDUREDECL_H
#define NODEPROCEDUREDECL_H

#include "source/Compiler/token.h"
#include "source/Compiler/pvar.h"
#include "source/Compiler/symboltable.h"
#include "source/Compiler/errorhandler.h"
#include "source/Compiler/ast/node.h"
#include "source/Compiler/ast/nodeblock.h"
#include "source/Compiler/ast/nodevardecl.h"

class NodeProcedureDecl : public Node {
public:
    QString m_procName;
    QVector<Node*> m_paramDecl;
    bool m_isInterrupt;
    Node* m_block = nullptr;


    NodeProcedureDecl(Token t, QString m);


    NodeProcedureDecl(Token t, QString m, QVector<Node*> paramDecl, Node* block, bool isInterrupt=false);

    void Delete() override;

    void SetParametersValue(QVector<PVar>& lst);


    QString Build(Assembler* as) override;

    PVar Execute(SymbolTable* symTab, uint lvl) override;
    void ExecuteSym(SymbolTable* symTab) override;
};

#endif // NODEPROCEDUREDECL_H
