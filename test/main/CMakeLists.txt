idf_component_register(SRCS
                        "main_test.c"
                        "engine_test.c"
                         "../../main/engine.c"
                    INCLUDE_DIRS
                        "."
                        "../../main/include"
                    REQUIRES unity)