flextGL
=======

flextGL is an OpenGL extension loader generator.

It is a bit different than other comparable systems:

 * Gives complete control over exposed version and extensions
 * (Optionally) exports only core-profile functions
 * Only requested extensions are loaded
 * Bindings directly generated from opengl.org `*.spec` files
 * Flexible python template system for source-generation
 * Source templates easy to adapt to project requirements

You will need the following dependencies:

 * [Python 3.2](http://python.org)
 * [Wheezy Template](http://packages.python.org/wheezy.template)

### What's new?

This new version is a major rewrite that should make the spec parser quite a bit more manageable.

Added support for Python 3 and replaced Cheetah with Wheezy for templating.

Source tree
-----------

* `flextGLgen.py`
  > The generator script.

* `templates/`
  > The  sub-directories  in here  contain the different  template sets.
  > You can  add your own  template by simply  creating a new  folder in 
  > there.

* `profiles/`
  > Some example profile files to give  you an idea on how to write your 
  > own. 'profiles/exampleProfile.txt' contains a lot of comments to get
  > you up to speed.

* `example/`
  > A (very) small C++/GLFW example  on how to include flextGL into your 
  > project.
   
* `spec/` (generated)
  > This directory is  automatically created by the script  to store the
  > downloaded OpenGL .spec files.


Usage
-----

You create your  loader code by writing a profile  file and passing it
to the script.

Here is what a typical profile might look like:

    version 3.3 core
    extension EXT_texture_filter_anisotropic optional
    extension ARB_tesselation_shader optional

This  requests   an  OpenGL  core  profile  and   the  extensions  for
anisotropic filtering and  tesselation shaders. Those extensions  were
requested  as 'optional'. This  means that  a missing  extension won't
cause  an error.  Instead, the  programmer will  have to  check before
using  it. This  can  be easily  done  by testing  a generated  global
variable.

The profile file is then passed to the script like this:

    $ python flextGLgen.py -D generated profile.txt

This  will  create  the  requested  source  code and  put  it  in  the
'generated' directory.

The  best  way  to work  with  flextGL  is  to  integrate it  in  your
build-system. The example project demonstrates this for Make.

Generated API
-------------

The generated API boils down to a few things:

* `int flextInit()`
  > Initializes the OpenGL functions after context creation. 

* `FLEXT_MAJOR_VERSION`
  > The OpenGL major version defined in the profile file.

* `FLEXT_MINOR_VERSION`
  > The OpenGL minor version defined in the profile file.

* `FLEXT_CORE_PROFILE`
  > Boolean variable.  Is GL_TRUE,  if the profile  file defined  a core
  > profile. 

* `FLEXT_<extension-name>`
  > Generated global  variables for checking if a  specific extension is
  > supported. 

Take a look at the example program to get an idea on how it's used.

Templates
---------

At the moment, there are two template sets available:

* `'compatible'`
  > This loads the extensions using a framework-agnostic method with WGL
  > AGL or GLX. This  is  probably the sensible default for most people.
  > It has not been thoroughly tested yet, though.

* `'glfw'`
  > This  uses  GLFW's functions  for  loading  and  testing for  OpenGL
  > extensions.  It will  obviously only  work  with GLFW,  but is  well
  > tested and the generated source code is very easy to understand.


Copyright
---------

The  "compatible"  template uses  a few  code  snippets  from Slavomir
Kaslev's  gl3w  OpenGL core  profile loader  for  portable  loading of
procedures and checking minor/major version in OpenGL < 3.0.

    (C) Thomas Weber, 2011
        ginko (at) cg (dot) tuwien (dot) ac (dot) at
