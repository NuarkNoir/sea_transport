#ifndef APPARATUS_H
#define APPARATUS_H

#include "auth_system.h"
#include "object_system.h"

#include "../entities/vessel_entity.h"
#include "../entities/storage_entity.h"

#include <QString>
#include <QFile>
#include <QDataStream>


/**
 * @brief Main system class
 * 
 */
class apparatus {
private:
    //! Static pointer instance
    static apparatus *_instance;
    //! Static path to save file
    static const QString filename;

    //! Pointer to users subsystem 
    auth_system* _auth_system;
    //! Pointer to objects subsystem
    object_system* _object_system;

public:
    /**
     * @brief Construct a new apparatus object
     * 
     */
    explicit apparatus();
    /**
     * @brief Destroy the apparatus object
     * 
     */
    ~apparatus();

    /**
     * @brief Get the auth subsystem object
     * 
     * @return auth_system* 
     */
    auth_system* get_auth_subsystem();
    /**
     * @brief Get the object subsystem object
     * 
     * @return object_system* 
     */
    object_system* get_object_subsystem();

    /**
     * @brief Saves system data to disk
     * 
     */
    void save();
    /**
     * @brief Loads system data from disk
     * 
     */
    void load();

    /**
     * @brief Checks if it is first run
     * 
     * @return true 
     * @return false 
     */
    static bool is_first_run();
    /**
     * @brief Generates lock file after initialization
     * 
     */
    static void generate_lock_file();
    /**
     * @brief Get ther main system object
     * 
     * @return apparatus* 
     */
    static apparatus* instance();
    /**
     * @brief Initializes system on start
     * 
     */
    static void init();
    /**
     * @brief Shuts system down in the end
     * 
     */
    static void shutdown();
};

#endif // APPARATUS_H
