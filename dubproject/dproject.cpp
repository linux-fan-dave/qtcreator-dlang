#include "dproject.h"

namespace DubProject {
namespace Internal {

DProject* CreateDProject();
void ReleaseDProject(void*);

DProjectPtr DProject::create()
{
    return DProjectPtr(CreateDProject(), &ReleaseDProject);
}

}
}
