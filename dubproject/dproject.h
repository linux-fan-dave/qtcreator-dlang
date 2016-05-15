#ifndef DPROJECT_H
#define DPROJECT_H

#include <QSharedPointer>

namespace DubProject {
namespace Internal {

class DProject;
typedef QSharedPointer<DProject> DProjectPtr;

class DProject {
public:
    class ErrorData {
    public:
        QString errorString;
        bool isSucceeded;
    };
    typedef void(*ErrorHandler)(bool succeded, void* userData, const char* errorString);

    DProject() = delete;
    static DProjectPtr create();

    void load(const QString& directory);
    virtual void load(const char* directory, void* userData, ErrorHandler);
    virtual void reload(ErrorHandler);
private:

    static void fillErrorData(bool succeded, void* userData, const char* errorString);
};

}
}
#endif // DPROJECT_H
