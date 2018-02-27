import os
from conan.packager import ConanMultiPackager

if __name__ == "__main__":
    # print('-*-*-*-*-* FROM PYTHON -*-*-*-*-*-*-*')
    # print(os.getenv('BITPRIM_BUILD_NUMBER', '-'))
    # print('-*-*-*-*-* FROM PYTHON -*-*-*-*-*-*-*')

    builder = ConanMultiPackager(username="bitprim", channel="testing",
                                 remotes="https://api.bintray.com/conan/bitprim/bitprim",
                                 archs=["x86_64"])

    builder.add_common_builds(shared_option_name="test-abi:shared")

    filtered_builds = []
    for settings, options, env_vars, build_requires in builder.builds:
        if settings["build_type"] == "Release" and not options["test-abi:shared"]:

            # print(env_vars)
            env_vars["BITPRIM_BUILD_NUMBER"] = os.getenv('BITPRIM_BUILD_NUMBER', '-')
            # print(env_vars)

            if os.getenv('BITPRIM_RUN_TESTS', 'false') == 'true':
                options["test-abi:with_tests"] = "True"
                options["test-abi:with_examples"] = "True"

            filtered_builds.append([settings, options, env_vars, build_requires])


    builder.builds = filtered_builds
    builder.run()
