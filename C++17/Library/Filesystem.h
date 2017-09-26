#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED

#include <filesystem>
#include <iostream>
namespace Filesystem_Example
{
	void Filesystem()
	{
		//http://www.bfilipek.com/2017/08/cpp17-details-filesystem.html
		//Example based on this blog entry

		std::experimental::filesystem::path pathToShow("C:\Windows\notepad.exe");

		std::cout	<< "exists() = "		<< std::experimental::filesystem::exists(pathToShow) << "\n"
					<< "root_name() = "		<< pathToShow.root_name()		<< "\n"
					<< "root_path() = "		<< pathToShow.root_path()		<< "\n"
					<< "relative_path() = " << pathToShow.relative_path()	<< "\n"
					<< "parent_path() = "	<< pathToShow.parent_path()		<< "\n"
					<< "filename() = "		<< pathToShow.filename()		<< "\n"
					<< "stem() = "			<< pathToShow.stem()			<< "\n"
					<< "extension() = "		<< pathToShow.extension()		<< "\n";

		//TODO
		// - Directory
		// - Create/Delete files
		// - File information
		// - file flags
		// - file/folder linkage
	}
}

//#endif