set(SNORE_RCS ${SNORE_RCS} ${CMAKE_CURRENT_SOURCE_DIR}/../data/snore.qrc PARENT_SCOPE)


if(WITH_SNORE_DEAMON)
    if(WIN32)
      set(ICON_NAME zzz)
      FILE(TO_NATIVE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/${ICON_NAME}.ico ICON)
      string(REPLACE "\\" "\\\\" ICON ${ICON})
      file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${ICON_NAME}.rc "IDI_ICON1        ICON        DISCARDABLE    \"${ICON}\"\n")
      set(SNORENOTIFY_DEAMON_DEPS ${SNORENOTIFY_DEPS} ${CMAKE_CURRENT_BINARY_DIR}/${ICON_NAME}.rc PARENT_SCOPE)
    endif(WIN32)

    if(KDE4_FOUND)
      install(FILES snore.png DESTINATION ${ICON_INSTALL_DIR}/hicolor/48x48/apps)
      if(CMAKE_INSTALL_PREFIX STREQUAL "/usr")
        install(FILES snore.png DESTINATION /usr/share/pixmaps)
      endif(CMAKE_INSTALL_PREFIX STREQUAL "/usr")
    endif(KDE4_FOUND)
endif()
