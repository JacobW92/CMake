/*=========================================================================

  Program:   CMake - Cross-Platform Makefile Generator
  Module:    $RCSfile$
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) 2002 Kitware, Inc., Insight Consortium.  All rights reserved.
  See Copyright.txt or http://www.cmake.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef cmDependsJava_h
#define cmDependsJava_h

#include "cmDepends.h"

/** \class cmDependsJava
 * \brief Dependency scanner for Java class files.
 */
class cmDependsJava: public cmDepends
{
public:
  /** Checking instances need to know the build directory name and the
      relative path from the build directory to the target file.  */
  cmDependsJava(const char* dir, const char* targetFile);

  /** Scanning need to know the build directory name, the relative
      path from the build directory to the target file and the source
      file to scan.  */
  cmDependsJava(const char* dir, const char* targetFile,
                const char* sourceFile);

  /** Virtual destructor to cleanup subclasses properly.  */
  virtual ~cmDependsJava();

protected:
  // Implement writing/checking methods required by superclass.
  virtual bool WriteDependencies(std::ostream& os);
  virtual bool CheckDependencies(std::istream& is);

  // The source file from which to start scanning.
  std::string m_SourceFile;

private:
  cmDependsJava(cmDependsJava const&); // Purposely not implemented.
  void operator=(cmDependsJava const&); // Purposely not implemented.
};

#endif
