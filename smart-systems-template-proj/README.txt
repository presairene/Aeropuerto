This is the README document of the Smart Systems template VS project and is done with MARKDOWN formatting. It contains the info on content, prerequisites and how to install it in your computer.

This project is fully compatible with Git and you are strongly encouraged to use it for the subject. The gitignore file has been configured too.

#PROJECT INFO
- Author: Carlos Becker Robles
- Creation date: Oct 2021
- Last update date: 30 Sept 2022

#PREREQUISITES
You will need to have installed in your computer:
- Visual Studio: in this subject we will use Visual Studio Community 2019
- Python. Install the latest version and add it to the path during installation.
- MySQL connector repository. Distributed by the subject teacher.
- For full local development of the project: intelligence + database you will need to have installed too the MySQL server.
##MYSQL server & Workbench installation
1. Go to: https://dev.mysql.com/downloads/
2. Select and save the Microsoft Installer for Windows
3. Open the MySQL Installer and install MySQL Community Server and Workbench packages.
##MySQL Community Server config:
- Set the comms port to 3306.
- Set as password: 'root'.
- Leave the rest of settings as default

#INSTALLATION PROCESS
Make sure you havee downloaded the project folder and the MySQL repository folder
##Dependency installation
###First steps. (If it is the first time you open Miniconda and have not installed Conda)
1. Open your computer command prompt and run
''
pip install conda
''
2. Navigate to the MySQL connector repository folder
3. Run the following command
''
conan create . smartSys/testing
''
###Project dependency installation(If is the first time you are going to run the project in your computer)
1. Open the Miniconda prompt and navigate to your conan directory of your project
2. Run the following commands one at a time to build the dependencies of the project including the MySQL connector. Each should take a little while to run.
''
conan install . -g visual_studio_multi -s arch=x86_64 -s build_type=Debug -s compiler.version=16 --build mysql-connector-cpp
conan install . -g visual_studio_multi -s arch=x86_64 -s build_type=Release -s compiler.version=16 --build mysql-connector-cpp
''
4. Open the project (.sln file) in Visual Studio
5. Go to 'Property Manager' next to 'Solution Explorer'
6. Right click the name of the project and select 'Add Existing Property Sheet'
7. Select the conanbuildinfo_multi.props file.
8. Make sure your project is in x64 and Debug building mode.

You are ready to build the project!
