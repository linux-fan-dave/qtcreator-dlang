#ifndef DPROJECT_H
#define DPROJECT_H

#include <QSharedPointer>

namespace DubProject {
namespace Internal {

class DProject;
typedef QSharedPointer<DProject> DProjectPtr;

class DProject {
public:
    typedef void(*ErrorHandler)(bool succeded, const char* errorString);

    DProject() = delete;
    static DProjectPtr create();

    virtual void load(const char* , ErrorHandler);
    virtual void reload(ErrorHandler);
};

}
}
#endif // DPROJECT_H
