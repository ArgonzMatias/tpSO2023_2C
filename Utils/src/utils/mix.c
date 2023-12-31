#include "mix.h"

int config_init(void* moduleConfig, char* pathToConfig, t_log* moduleLogger,
                void (*config_initializer)(void* moduleConfig, t_config* tempConfig)) {
    t_config* tempConfig = config_create(pathToConfig);
    if (NULL == tempConfig) {
        log_error(moduleLogger, "Path \"%s\" no encontrado", pathToConfig);
        return -1;
    }
    config_initializer(moduleConfig, tempConfig);
    log_info(moduleLogger, "Inicialización de campos correcta"); //esto me tira error nose pq
    config_destroy(tempConfig);
    return 1;
}




