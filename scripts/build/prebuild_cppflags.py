Import("env")

env.Append(CXXFLAGS=[
    "-std=gnu++2a" # The ESPs toolchain uses some gnu-specific extensions, so we need to use gnu-flavour of the standard
])

if env.GetBuildType() == "debug":
    env.Append(CCFLAGS=[
        "-Wall"
    ])
else:
    env.Append(CPPDEFINES=[
        "NDEBUG"
    ])