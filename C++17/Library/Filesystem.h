#pragma once



#include <filesystem>
#include <iostream>

namespace Filesystem_Example
{
	void Filesystem()
	{
		//http://www.bfilipek.com/2017/08/cpp17-details-filesystem.html
		//Example based on this blog entry

		//TODO MORE THOROOUGH EXAMPLES

		std::experimental::filesystem::path pathToShow("C:\\Windows\\notepad.exe");

		std::cout	<< "exists() = "		<< std::experimental::filesystem::exists(pathToShow) << "\n"
					<< "root_name() = "		<< pathToShow.root_name()		<< "\n"
					<< "root_path() = "		<< pathToShow.root_path()		<< "\n"
					<< "relative_path() = " << pathToShow.relative_path()	<< "\n"
					<< "parent_path() = "	<< pathToShow.parent_path()		<< "\n"
					<< "filename() = "		<< pathToShow.filename()		<< "\n"
					<< "stem() = "			<< pathToShow.stem()			<< "\n"
					<< "extension() = "		<< pathToShow.extension()		<< "\n";

		//std::path
		std::experimental::filesystem::path someFilePath("C:\\Windows\\notepad.exe");
		
		//std::directory_entry
		std::experimental::filesystem::directory_entry someDirectory("C:\\Windows\\");
		std::experimental::filesystem::directory_entry thisRelativeDirectory(".\\");

		//std::directory_iterator
		std::experimental::filesystem::directory_iterator dir_iter(thisRelativeDirectory);
		for (auto& p : dir_iter)
			std::cout << p << '\n';
		
		//std::recursive_directory_iterator
		std::experimental::filesystem::recursive_directory_iterator dir_rev_iter(thisRelativeDirectory);
		for (auto& p : dir_rev_iter)
			std::cout << p << '\n';

		//std::file_status | std::status
		std::experimental::filesystem::file_status file_status_obj = std::experimental::filesystem::status(someFilePath);

		//std::space_info | std::space
		std::experimental::filesystem::space_info cSpace = std::experimental::filesystem::space("C:\\");

		std::cout	<< ".        Capacity       Free      Available\n"
					<< "C:\\:   "	<<	cSpace.capacity << "   "
					<< cSpace.free	<< "   "			<< cSpace.available << '\n';

		//std::file_type 
		std::experimental::filesystem::file_type ft = file_status_obj.type();

		//std::file_time_type
		std::experimental::filesystem::file_time_type ftime = std::experimental::filesystem::last_write_time(someFilePath);
		//std::perms
		std::experimental::filesystem::perms permissions = file_status_obj.permissions();

		//std::perm_options
		#ifdef MSVC_NOT_SUPPORTED_ENABLED

		std::experimental::filesystem::permissions(somePath, std::experimental::filesystem::perms::owner_all | 
															 std::experimental::filesystem::perms::group_all, 
															 std::experimental::filesystem::perm_options::add);
		#endif
		
		//std::directory_options
			//Not used or fully defined in MSVC
			//std::experimental::filesystem::directory_options::follow_directory_symlink

		//std::file_time_type | std::last_write_time
		std::experimental::filesystem::file_time_type fileTime = std::experimental::filesystem::last_write_time(someFilePath);

		//std::absolute | std::equivalent
		std::experimental::filesystem::path relPath(".\\CPPExtensionExample.exe");
		std::experimental::filesystem::path absPath = std::experimental::filesystem::absolute(relPath);
		bool isAbs = absPath.is_absolute();
		bool isRelative = absPath.is_relative();

		// The result of absolute path is not absolute... so this crashes...
		//bool isPathSame = std::experimental::filesystem::equivalent(relPath, absPath);

		//std::canonical | std::weakly_canonical
		std::experimental::filesystem::path cannonicalPath = std::experimental::filesystem::canonical(relPath);

		#ifdef MSVC_NOT_SUPPORTED_ENABLED
		std::experimental::filesystem::path weaklyCannonicalPath = std::experimental::filesystem::weakly_canonical(relPath);
		#endif
		
		//std::relative
		#ifdef MSVC_NOT_SUPPORTED_ENABLED
		std::experimental::filesystem::path relativePath = std::experimental::filesystem::relative(somePath);
		#endif

		//std::proximate
		#ifdef MSVC_NOT_SUPPORTED_ENABLED
		std::experimental::filesystem::path relativePath = std::experimental::filesystem::proximate(somePath);
		#endif

		//std::remove | std::copy | std::copy_file
		std::experimental::filesystem::copy(someFilePath, ".\\notepad.exe", std::experimental::filesystem::copy_options::overwrite_existing);
		bool removed = std::experimental::filesystem::remove(".\\notepad.exe");
			//copy_options::recursive is also useful for but tricky to demo without some certain data...

		std::experimental::filesystem::copy_file(someFilePath, ".\\notepad.exe", std::experimental::filesystem::copy_options::overwrite_existing);
		removed = std::experimental::filesystem::remove(".\\notepad.exe");

		//std::copy_symlink
		//TODO
		//std::create_directory
		std::experimental::filesystem::create_directory("New_Dir");

		//std::create_directories
		std::experimental::filesystem::create_directories("New_Dirs/a");

		//std::create_hard_link
		//TODO

		//std::create_symlink
		//TODO

		//std::create_directory_symlink
		//TODO

		//std::current_path
		std::experimental::filesystem::path thisLocation = std::experimental::filesystem::current_path();
		std::cout << "Current directory = " << thisLocation.string() << "\n";
		std::experimental::filesystem::current_path(someDirectory);
		std::experimental::filesystem::path newLocLocation = std::experimental::filesystem::current_path();
		std::cout << "Changed working directory to = " << newLocLocation.string() << "\n"
			;
		std::experimental::filesystem::current_path(thisLocation);
		thisLocation = std::experimental::filesystem::current_path();
		std::cout << "Reset working directory to = " << thisLocation.string() << "\n";

		//std::exists
		bool doesFileExist = std::experimental::filesystem::exists(someFilePath);

		//std::file_size
		std::uintmax_t filesize = std::experimental::filesystem::file_size(someFilePath);

		//std::hard_link_count
		//TODO

		//std::read_symlink
		//TODO

		// std::remove_all | std::temp_directory_path
		std::experimental::filesystem::path dir = std::experimental::filesystem::temp_directory_path();
		std::experimental::filesystem::create_directories( "newDirTest/example");
		std::uintmax_t n = std::experimental::filesystem::remove_all("newDirTest");
		std::cout << "Deleted " << n << " files\n";

		//std::rename
		std::experimental::filesystem::copy(someFilePath, ".\\notepad.exe", std::experimental::filesystem::copy_options::overwrite_existing);
		std::experimental::filesystem::rename(".\\notepad.exe", ".\\notepad_rename.exe");
		bool removed_renamed = std::experimental::filesystem::remove(".\\notepad_rename.exe");

		//std::resize_file
		std::experimental::filesystem::copy(someFilePath, ".\\notepad.exe", std::experimental::filesystem::copy_options::overwrite_existing);
		std::experimental::filesystem::resize_file(".\\notepad.exe", 1024); //size in bytes
		bool removed_resized = std::experimental::filesystem::remove(".\\notepad.exe");

		//std::status_known
		bool isit = std::experimental::filesystem::status_known(file_status_obj);
		//std::is_block_file
		isit = std::experimental::filesystem::is_block_file(someFilePath);
		//std::is_character_file
		isit = std::experimental::filesystem::is_character_file(someFilePath);
		//std::is_directory
		isit = std::experimental::filesystem::is_directory(someFilePath);
		//std::is_empty
		isit = std::experimental::filesystem::is_empty(someFilePath);
		//std::is_fifo
		isit = std::experimental::filesystem::is_fifo(someFilePath);
		//std::is_other
		isit = std::experimental::filesystem::is_other(someFilePath);
		//std::is_regular_file
		isit = std::experimental::filesystem::is_regular_file(someFilePath);
		//std::is_socket
		isit = std::experimental::filesystem::is_socket(someFilePath);
		//std::is_symlink
		isit = std::experimental::filesystem::is_symlink(someFilePath);


		//TODO 
		// Member variables for path
		// other general member variables.
	}
}

//#endif