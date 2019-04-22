function(copper_config_framework LIBNAME)
  message("Configuring ${LIBNAME} framework")

  set_target_properties(${LIBNAME} PROPERTIES 
    FRAMEWORK TRUE
    FRAMEWORK_VERSION "${PROJECT_VERSION}" 
    MACOSX_FRAMEWORK_IDENTIFIER "com.redsoft.copperFramework"
  )

  # Set the INSTALL_PATH so that frameworks can be installed in the application package
  set_target_properties( ${LIBNAME} PROPERTIES 
    BUILD_WITH_INSTALL_RPATH 1
    INSTALL_NAME_DIR "${CMAKE_INSTALL_PREFIX}/Frameworks"
    #INSTALL_NAME_DIR "@executable_path/../../../Frameworks"
  )

  set_target_properties(${LIBNAME} PROPERTIES PUBLIC_HEADER "${HEADER_FILES};${PLATFORM_HEADERS};" )
  set_target_properties(${LIBNAME} PROPERTIES RESOURCE "${RESOURCE_FILES}")
  set_source_files_properties("${RESOURCE_FILES}" PROPERTIES MACOSX_PACKAGE_LOCATION Resources)

  set_target_properties(${LIBNAME} PROPERTIES OUTPUT_NAME ${LIBNAME})
endfunction(copper_config_framework)