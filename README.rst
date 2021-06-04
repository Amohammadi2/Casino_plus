Casino_plus
==============
easily create uniform and non-uniform random distributions

build instructions
-----------------------
follow these instrucitons to setup the prjoect


Gnu/Linux
~~~~~~
requirements:

- CMake 3.8 or higher

.. code:: bash

   $ cd Casino_plus  # root dir
   $ mkdir build
   $ cd build
   $ cmake ..
   $ cmake --build .


Windows
~~~~~~~
requirements:

- Visual Studio 2017 or higher
- CMake 3.8 or higher

open up visual studio, select the configuration you want and build it
or just give it a :code:`cmake --build .` after configuring the project manually

how to use C++ interface
-------------------------
This project supports CMake. if you want to use this project in a CMake
project, you can simply include it using FetchContent module from CMake.
Note that this requires your CMAke version to be 3.12 or higher

.. code:: cmake
   include (FetchContent)
   FetchContent_Declare(
      cplus
      GIT_REPOSITORY https://github.com/Amohammadi2/Casino_plus.git
      GIT_TAG v1.0.1
   )
   if(NOT cplus_POPULATED)
      FetchContent_Populate(cplus)
      add_subdirectory(${cplus_SOURCE_DIR} ${cplus_BINARY_DIR})
   endif()

adding the codes above to your **CMakeLists.txt** file will download the repo
as a dependency of your project. then you'll need to link the library against
your project targets:

.. code:: cmake
   # just as an example
   project (someproject)
   add_executable(someexecutable "src/source.cpp")
   target_link_libraries(someexecutable Casino_plus)

adding the codes above, will make **Casino_plus.h** header file available 
and links **Casino_plus** library to your executable.


usage
-----
here is an example program

.. code:: cpp
   #include <iostream> // std::cout
   #include <string> // std::string
   #include <utility> // std::pair
   #include <Casino_plus.h> // CasinoRandomGenerator class

   int main() {
      // construct a new generator
      CasinoRandomGenerator<std::string> rand;
      // add a single item
      rand.add_item("Ashkan", 1)
      std::pair<std::string, int> my_brothers[]  = {
         {"Arshia", 1},
         {"Ilia", 2}
      };
      // or add multiple items at once
      rand.add_items(my_brothers);
      // get a random value out of that
      std::cout << /*returns std::string */ rand.get_random_item() << std::endl;
      return 0;
   }


python binding installation
----------------------------
requirements:

- Visual C++ build tools 2017 or higher
- CMake 3.8 or higher

.. code:: bash

 $ python setup.py install


how to use python interface
----------------------------
This module is very developer-friendly and easy to use.
first you should basically import the module after you have
it installed.

.. code:: python

 import CasinoPlus


the module contains a class called `CasinoRandomGenerator` but because
of constraints of C++ type system, there are some prefixes that you should
prepend to the name of the class in order to import it.  

here are the possible prefixes you can use:

- s_ : for generators containing strings
- cs_ : for generators containing characters
- i_ : for generators containing integers
- f_ : for generators containing floating point values
- d_ : for generators containing doubles

example: :code:`s_CasinoRandomGenerator` can contain strings as items

adding items to the generator
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
in order to add new items to the generator you should use either
:code:`add_item` or :code:`add_sequence`.

- :code:`add_item (item, probability_chance: int) -> None` : adds one single 
item to the generator
* :code:`add_sequence (items: List[Tuple[Item_Type, int]]) -> None` : can add
multiple items at once. :code:`Item_Type` is actually the type of the generator
you're using. For example, if you are using "s_CasinoRandomGenerator" class,
then :code:`Item_Type` would be :code:`str`. it is exactly the same case with other
variations of CasinoRandomGenerator class

getting a random value out of the generator
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
to get a random value, you can use :code:`get_random_item` method

.. code:: python

 rand_item = gen.get_random_item()


Support
--------
by supporting this project, you help us grow and get better.

.. image:: https://coffeebede.ir/DashboardTemplateV2/app-assets/images/banner/default-yellow.svg
   :target: https://coffeebede.ir/buycoffee/ashkan_mohammadi
