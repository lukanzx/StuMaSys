cmake_minimum_required(VERSION 3.5)

project(cmake-StuSystem-01 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Sql)

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}/DatabaseEntityClass/StudentsBasicInformation/"
    "${CMAKE_CURRENT_SOURCE_DIR}/DatabaseEntityClass/AdministratorBasicInformation/"
    "${CMAKE_CURRENT_SOURCE_DIR}/DatabaseEntityClass/StudentPasswordTable/"
    "${CMAKE_CURRENT_SOURCE_DIR}/DatabaseEntityClass/AdministratorPasswordTable/"
    "${CMAKE_CURRENT_SOURCE_DIR}/DatabaseEntityClass/StudentGradesTable/"
    "${CMAKE_CURRENT_SOURCE_DIR}/DatabaseEntityClass/StudentHealthSate/"

    #---------------------------------------------
    "${CMAKE_CURRENT_SOURCE_DIR}/tool/Global/"
    #---------------------------------------------
    "${CMAKE_CURRENT_SOURCE_DIR}/window/LoginAttachmentWindows/Register/"
    #---------------------------------------------
    "${CMAKE_CURRENT_SOURCE_DIR}/window/LoginAttachmentWindows/RetrievePassword/"
    #---------------------------------------------
    "${CMAKE_CURRENT_SOURCE_DIR}/window/Administrator/"
    #---------------------------------------------
    "${CMAKE_CURRENT_SOURCE_DIR}/window/Student/"
    #---------------------------------------------
    "${CMAKE_CURRENT_SOURCE_DIR}/window/LogIn/"

    "${CMAKE_CURRENT_SOURCE_DIR}/window/AdministratorAttachmentWindows/AllStudentInformation/"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/AdministratorAttachmentWindows/AddStudent/"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/AdministratorAttachmentWindows/ModifyStudentPassword/"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/AdministratorAttachmentWindows/ModifyAdministratorPassword/"

    "${CMAKE_CURRENT_SOURCE_DIR}/window/AdministratorAttachmentWindows/AllStudentGrades/"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/AdministratorAttachmentWindows/AllStudentGrades/AddStudentGrades/"

    "${CMAKE_CURRENT_SOURCE_DIR}/window/AdministratorAttachmentWindows/ModifyStudentInformation/"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/AdministratorAttachmentWindows/StudentEpidemicManagement/"

    "${CMAKE_CURRENT_SOURCE_DIR}/window/StudentAttachmentWindows/StudentSelfModifyPassword/"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/StudentAttachmentWindows/StudentSelfSelectGrades/"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/StudentAttachmentWindows/StudentSelfShowInformation/"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/StudentAttachmentWindows/StudentNotes/"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/StudentAttachmentWindows/StudentMail/"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/StudentAttachmentWindows/StudentHealth/"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/StudentAttachmentWindows/StudentFeedback/"



)
#===============================================================================================================================

set(PROJECT_SOURCES

    #---------------------------------------------
    README.md
    main.cpp
    #---------------------------------------------
    "${CMAKE_CURRENT_SOURCE_DIR}/DatabaseEntityClass/StudentsBasicInformation/StudentsBasicInformation.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/DatabaseEntityClass/StudentsBasicInformation/StudentsBasicInformation.h"


    "${CMAKE_CURRENT_SOURCE_DIR}/DatabaseEntityClass/AdministratorBasicInformation/AdministratorBasicInformation.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/DatabaseEntityClass/AdministratorBasicInformation/AdministratorBasicInformation.h"

    "${CMAKE_CURRENT_SOURCE_DIR}/DatabaseEntityClass/StudentPasswordTable/StudentPasswordTable.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/DatabaseEntityClass/StudentPasswordTable/StudentPasswordTable.h"

    "${CMAKE_CURRENT_SOURCE_DIR}/DatabaseEntityClass/AdministratorPasswordTable/AdministratorPasswordTable.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/DatabaseEntityClass/AdministratorPasswordTable/AdministratorPasswordTable.h"

    "${CMAKE_CURRENT_SOURCE_DIR}/DatabaseEntityClass/StudentGradesTable/StudentGradesTable.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/DatabaseEntityClass/StudentGradesTable/StudentGradesTable.h"

    "${CMAKE_CURRENT_SOURCE_DIR}/DatabaseEntityClass/StudentHealthSate/StudentHealthSate.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/DatabaseEntityClass/StudentHealthSate/StudentHealthSate.h"

#    #---------------------------------------------
    "${CMAKE_CURRENT_SOURCE_DIR}/tool/Global/Global.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/tool/Global/Global.h"
    #---------------------------------------------
    "${CMAKE_CURRENT_SOURCE_DIR}/window/LoginAttachmentWindows/Register/Register.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/LoginAttachmentWindows/Register/Register.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/LoginAttachmentWindows/Register/Register.ui"
    #---------------------------------------------
    "${CMAKE_CURRENT_SOURCE_DIR}/window/LoginAttachmentWindows/RetrievePassword/RetrievePassword.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/LoginAttachmentWindows/RetrievePassword/RetrievePassword.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/LoginAttachmentWindows/RetrievePassword/RetrievePassword.ui"

    "${CMAKE_CURRENT_SOURCE_DIR}/window/Administrator/Administrator.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/Administrator/Administrator.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/Administrator/Administrator.ui"

    "${CMAKE_CURRENT_SOURCE_DIR}/window/Student/Student.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/Student/Student.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/Student/Student.ui"

    "${CMAKE_CURRENT_SOURCE_DIR}/window/LogIn/LogIn.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/LogIn/LogIn.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/LogIn/LogIn.ui"

    "${CMAKE_CURRENT_SOURCE_DIR}/window/AdministratorAttachmentWindows/AllStudentInformation/AllStudentInformation.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/AdministratorAttachmentWindows/AllStudentInformation/AllStudentInformation.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/AdministratorAttachmentWindows/AllStudentInformation/AllStudentInformation.ui"

    "${CMAKE_CURRENT_SOURCE_DIR}/window/AdministratorAttachmentWindows/AddStudent/AddStudent.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/AdministratorAttachmentWindows/AddStudent/AddStudent.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/AdministratorAttachmentWindows/AddStudent/AddStudent.ui"

    "${CMAKE_CURRENT_SOURCE_DIR}/window/AdministratorAttachmentWindows/ModifyStudentPassword/ModifyStudentPassword.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/AdministratorAttachmentWindows/ModifyStudentPassword/ModifyStudentPassword.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/AdministratorAttachmentWindows/ModifyStudentPassword/ModifyStudentPassword.ui"

    "${CMAKE_CURRENT_SOURCE_DIR}/window/AdministratorAttachmentWindows/ModifyAdministratorPassword/ModifyAdministratorPassword.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/AdministratorAttachmentWindows/ModifyAdministratorPassword/ModifyAdministratorPassword.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/AdministratorAttachmentWindows/ModifyAdministratorPassword/ModifyAdministratorPassword.ui"

    "${CMAKE_CURRENT_SOURCE_DIR}/window/AdministratorAttachmentWindows/AllStudentGrades/AllStudentGrades.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/AdministratorAttachmentWindows/AllStudentGrades/AllStudentGrades.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/AdministratorAttachmentWindows/AllStudentGrades/AllStudentGrades.ui"

    "${CMAKE_CURRENT_SOURCE_DIR}/window/AdministratorAttachmentWindows/AllStudentGrades/AddStudentGrades/AddStudentGrades.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/AdministratorAttachmentWindows/AllStudentGrades/AddStudentGrades/AddStudentGrades.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/AdministratorAttachmentWindows/AllStudentGrades/AddStudentGrades/AddStudentGrades.ui"

    "${CMAKE_CURRENT_SOURCE_DIR}/window/AdministratorAttachmentWindows/ModifyStudentInformation/ModifyStudentInformation.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/AdministratorAttachmentWindows/ModifyStudentInformation/ModifyStudentInformation.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/AdministratorAttachmentWindows/ModifyStudentInformation/ModifyStudentInformation.ui"

    "${CMAKE_CURRENT_SOURCE_DIR}/window/AdministratorAttachmentWindows/StudentEpidemicManagement/StudentEpidemicManagement.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/AdministratorAttachmentWindows/StudentEpidemicManagement/StudentEpidemicManagement.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/AdministratorAttachmentWindows/StudentEpidemicManagement/StudentEpidemicManagement.ui"
 
    "${CMAKE_CURRENT_SOURCE_DIR}/window/StudentAttachmentWindows/StudentSelfModifyPassword/StudentSelfModifyPassword.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/StudentAttachmentWindows/StudentSelfModifyPassword/StudentSelfModifyPassword.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/StudentAttachmentWindows/StudentSelfModifyPassword/StudentSelfModifyPassword.ui"

    "${CMAKE_CURRENT_SOURCE_DIR}/window/StudentAttachmentWindows/StudentSelfSelectGrades/StudentSelfSelectGrades.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/StudentAttachmentWindows/StudentSelfSelectGrades/StudentSelfSelectGrades.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/StudentAttachmentWindows/StudentSelfSelectGrades/StudentSelfSelectGrades.ui"

    "${CMAKE_CURRENT_SOURCE_DIR}/window/StudentAttachmentWindows/StudentSelfShowInformation/StudentSelfShowInformation.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/StudentAttachmentWindows/StudentSelfShowInformation/StudentSelfShowInformation.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/StudentAttachmentWindows/StudentSelfShowInformation/StudentSelfShowInformation.ui"

    "${CMAKE_CURRENT_SOURCE_DIR}/window/StudentAttachmentWindows/StudentNotes/StudentNotes.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/StudentAttachmentWindows/StudentNotes/StudentNotes.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/StudentAttachmentWindows/StudentNotes/StudentNotes.ui"

    "${CMAKE_CURRENT_SOURCE_DIR}/window/StudentAttachmentWindows/StudentMail/StudentMail.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/StudentAttachmentWindows/StudentMail/StudentMail.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/StudentAttachmentWindows/StudentMail/StudentMail.ui"

    "${CMAKE_CURRENT_SOURCE_DIR}/window/StudentAttachmentWindows/StudentHealth/StudentHealth.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/StudentAttachmentWindows/StudentHealth/StudentHealth.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/StudentAttachmentWindows/StudentHealth/StudentHealth.ui"

    "${CMAKE_CURRENT_SOURCE_DIR}/window/StudentAttachmentWindows/StudentFeedback/StudentFeedback.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/StudentAttachmentWindows/StudentFeedback/StudentFeedback.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/window/StudentAttachmentWindows/StudentFeedback/StudentFeedback.ui"

)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(cmake-StuSystem-01
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )

else()
    if(ANDROID)
        add_library(cmake-StuSystem-01 SHARED
            ${PROJECT_SOURCES}
        )

    else()
        add_executable(cmake-StuSystem-01
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(cmake-StuSystem-01 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(cmake-StuSystem-01 PRIVATE Qt6::Sql)


set_target_properties(cmake-StuSystem-01 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS cmake-StuSystem-01
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(cmake-StuSystem-01)
endif()
