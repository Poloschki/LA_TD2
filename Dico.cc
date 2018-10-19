#include "Dico.h"

Definition::Definition(char *m, char *def)
{
    clef = CString(m);
    definition = CString(def);
}

CString Definition::GetClef() const
{
    return clef;
}

CString Definition::GetDef() const
{
    return definition;
}

Definition::~Definition()
{
    cout<<"dest "<<clef.GetString()<<"-";
}
