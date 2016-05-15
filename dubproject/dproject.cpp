#include "dproject.h"

DProject* CreateDProject();
void ReleaseDProject(void*);

DProjectPtr DProject::create()
{
    return DProjectPtr(CreateDProject(), &ReleaseDProject);
}
