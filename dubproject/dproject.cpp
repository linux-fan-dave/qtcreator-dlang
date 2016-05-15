#include "dproject.h"
#include <stdexcept>

namespace DubProject {
namespace Internal {

DProject* CreateDProject();
void ReleaseDProject(void*);



DProjectPtr DProject::create()
{
    return DProjectPtr(CreateDProject(), &ReleaseDProject);
}

void DProject::load(const QString &directory)
{
    ErrorData ed;
    load(directory.toUtf8().constData(), &ed, &DProject::fillErrorData);

    if(!ed.isSucceeded) {
        throw std::runtime_error(ed.errorString.toUtf8().constData());
    }
}

void DProject::fillErrorData(bool succeded, void *userData, const char *errorString)
{
    ErrorData* ed = (ErrorData*) userData;
    ed->errorString = QString::fromUtf8(errorString);
    ed->isSucceeded = succeded;
}

}
}
