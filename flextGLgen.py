
import flext

def main():
    options,profile = flext.parse_args()
    version,extensions = flext.parse_profile(profile)

    flext.download_spec(options.download)
    typemap = flext.parse_typemap()

    categories = flext.find_categories(version, extensions, False)
    enums = flext.parse_enums()
    functions, passthru = flext.parse_functions(categories, typemap)
    
    flext.generate_source(options, version, enums, functions, passthru, extensions)
    
    
    



if __name__ == "__main__":
    main()
