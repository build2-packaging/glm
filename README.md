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

    depends: glm ^1.0.0

The library can be imported by the following declaration in a `buildfile`.

    import glm = glm%lib{glm}

## Configuration
There are no configuration options available.

## Issues and Notes
- This package does not support the GLM C++ module that has been added in version 1.0.0 because support for C++ modules is still lacking in compilers.
- As there are too many configuration macros, no precompiled library target is provided. The file `details/glm.cpp` is not part of the package.
- The original `gtx/matrix_factorization.inl` file is not UTF-8 encoded and has therefore been replaced by a copy that was first transformed to encoded it with UTF-8.
- The `gtc/gtc_bitfield.cpp` test fails for optimized Clang 16 configurations.
- Trying to compile the `core/core_setup_message.cpp` test leads inconsistent compiler behavior errors on some target configurations and has therefore been disabled.
- Some tests have been disabled to make the package with its tests compilable.

## Contributing
Thanks in advance for your help and contribution to keep this package up-to-date.
For now, please, file an issue on [GitHub](https://github.com/build2-packaging/glm/issues) for everything that is not described below.

### Recommend Updating Version
Please, file an issue on [GitHub](https://github.com/build2-packaging/glm/issues) with the new recommended version.

### Update Version by Pull Request
1. Fork the repository on [GitHub](https://github.com/build2-packaging/glm) and clone it to your local machine.
2. Run `git submodule init` and `git submodule update` to get the current upstream directory.
3. Inside the `upstream` directory, checkout the new library version `X.Y.Z` by calling `git checkout vX.Y.Z` that you want to be packaged.
4. If needed, change source files, `buildfiles`, and symbolic links accordingly to create a working build2 package. Make sure not to directly depend on the upstream directory inside the build system but use symbolic links instead.
5. Update library version in `manifest` file if it has changed or add package update by using `+n` for the `n`-th update.
6. Make an appropriate commit message by using imperative mood and a capital letter at the start and push the new commit to the `master` branch.
7. Run `bdep ci` and test for errors.
8. If everything works fine, make a pull request on GitHub and write down the `bdep ci` link to your CI tests.
9. After a successful pull request, we will run the appropriate commands to publish a new package version.

### Update Version Directly if You Have Permissions
1. Inside the `upstream` directory, checkout the new library version `X.Y.Z` by calling `git checkout vX.Y.Z` that you want to be packaged.
2. If needed, change source files, `buildfiles`, and symbolic links accordingly to create a working build2 package. Make sure not to directly depend on the upstream directory inside the build system but use symbolic links instead.
3. Update library version in `manifest` file if it has changed or add package update by using `+n` for the `n`-th update.
4. Make an appropriate commit message by using imperative mood and a capital letter at the start and push the new commit to the `master` branch.
5. Run `bdep ci` and test for errors and warnings.
6. When successful, run `bdep release --tag --push` to push new tag version to repository.
7. Run `bdep publish` to publish the package to [cppget.org](https://cppget.org).
