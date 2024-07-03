# build2 Package for GLM

This project builds and defines the build2 package for [GLM](https://github.com/g-truc/glm), also known as the OpenGL Mathematics (GLM) header-only C++ library for graphics software based on OpenGL Shading Language (GLSL) specifications.

[![Official](https://img.shields.io/website/https/github.com/g-truc/glm.svg?down_message=offline&label=Official&style=for-the-badge&up_color=blue&up_message=online)](https://github.com/g-truc/glm)
[![build2](https://img.shields.io/website/https/github.com/build2-packaging/glm.svg?down_message=offline&label=build2&style=for-the-badge&up_color=blue&up_message=online)](https://github.com/build2-packaging/glm)
[![cppget.org](https://img.shields.io/website/https/cppget.org/glm.svg?down_message=offline&label=cppget.org&style=for-the-badge&up_color=blue&up_message=online)](https://cppget.org/glm)
[![queue.cppget.org](https://img.shields.io/website/https/queue.cppget.org/glm.svg?down_message=empty&down_color=blue&label=queue.cppget.org&style=for-the-badge&up_color=orange&up_message=running)](https://queue.cppget.org/glm)

## Usage
Make sure to add the stable or alpha section of the `cppget.org` repository to your project's `repositories.manifest` to be able to fetch this package.

    :
    role: prerequisite
    location: https://pkg.cppget.org/1/stable
    # trust: ...

If the stable section of `cppget.org` is not an option then add this Git repository itself instead as a prerequisite.

    :
    role: prerequisite
    location: https://github.com/build2-packaging/glm.git

Add the respective dependency in your project's `manifest` file to make the package available for import.

    depends: glm ^1.0.1

The library can be imported by the following declaration in a `buildfile`.

    import glm = glm%lib{glm}

## Configuration
There are no configuration options available.

## Issues and Notes
- This package does not support the GLM C++ module that has been added in version 1.0.0 because support for C++ modules is still lacking in compilers.
- As there are too many configuration macros, no precompiled library target is provided. The file `details/glm.cpp` is not part of the package.
- The original `gtx/matrix_factorization.inl` file is not UTF-8 encoded and has therefore been replaced by a copy that was first transformed to encode it with UTF-8.
- The `gtc/gtc_bitfield.cpp` test randomly fails for optimized Clang configurations.
- Trying to compile the `core/core_setup_message.cpp` test leads to inconsistent compiler behavior errors on some target configurations and has therefore been disabled.
- Some tests have been disabled to make the package with its tests compilable.

## Contributing
Thank you in advance for your help and contribution to keep this package up-to-date.
Please, file an issue on [GitHub](https://github.com/build2-packaging/glm/issues) for questions, bug reports, or to recommend updating the package version.
If you're making a pull request to fix bugs or update the package version yourself, refer to the [`build2` Packaging Guidelines](https://build2.org/build2-toolchain/doc/build2-toolchain-packaging.xhtml#core-version-management).
