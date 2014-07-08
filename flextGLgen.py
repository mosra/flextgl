
import flext

def main():
    options,profile = flext.parse_args()
    version,extensions = flext.parse_profile(profile)

    flext.download_spec(options.download)

    passthru, enums, functions = flext.parse_xml(version, extensions)

    flext.generate_source(options, version, enums, functions, passthru, extensions)




if __name__ == "__main__":
    main()
