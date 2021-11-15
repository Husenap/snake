message("-- External Project: wraith")
include(FetchContent)

FetchContent_Declare(
    wraith
    GIT_REPOSITORY  https://github.com/KyaZero/Wraith.git
    GIT_TAG         v0.1.0-rc.3
)

set(Wraith_FOLDER "thirdparty/Wraith" CACHE STRING "" FORCE)

FetchContent_MakeAvailable(wraith)
