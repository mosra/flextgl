
import flext

def main():
    options,profile = flext.parse_args()
    version,extensions = flext.parse_profile(profile)

    flext.download_spec(False)
    typemap = flext.parse_typemap()

    categories = flext.find_categories(version, extensions, False)
    enums = flext.parse_enums()
    functions, passthru = flext.parse_functions(categories, typemap)
    #print (sorted(categories))
    #print (enums)
    #for t in sorted(typemap.keys()):
    #    print ('%s %s' % ((t+":").ljust(40), typemap[t]))
    # for cat,fs in sorted(functions.items()):
    #     print ('Category %s' % cat)
        # for f in fs:
        #     print ('\t%s' % f.to_string())
    
    flext.generate_source(options, version, enums, functions, passthru, extensions)
    
    
    



if __name__ == "__main__":
    main()
