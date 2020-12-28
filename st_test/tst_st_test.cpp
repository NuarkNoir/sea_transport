#include <QtTest>

#include "../sea_transport/entities/cargo_entity.h"
#include "../sea_transport/entities/storage_entity.h"
#include "../sea_transport/entities/dpoint_entity.h"
#include "../sea_transport/entities/vessel_entity.h"
#include "../sea_transport/entities/user_entity.h"

#include "../sea_transport/system/apparatus.h"
#include "../sea_transport/system/auth_system.h"
#include "../sea_transport/system/object_system.h"

#include <QFile>
#include <QDataStream>

class st_test : public QObject
{
    Q_OBJECT
    dpoint_entity *p;

public:
    st_test();
    ~st_test();

private slots:
    void initTestCase();
    void cleanupTestCase();

    void cargo_entity_serialization_test();
    void storage_entity_serialization_test();
    void dpoint_entity_serialization_test();
    void vessel_entity_serialization_test();
    void user_entity_serialization_test();

    void user_entity_password_verification_test();

    void apparatus_check_null_throws_error();

    void apparatus_check_first_run();
    void apparatus_check_first_registration();
    void apparatus_check_not_first_run();
    void apparatus_check_first_registered_user();
    void apparatus_check_remove_user();

    void object_subsystem_check_add_dpoint();
    void object_subsystem_check_find_dpoint();
    void object_subsystem_check_remove_dpoint();
};

st_test::st_test() {
    this->p = new dpoint_entity(0, "test");
}

st_test::~st_test() {

}

//=================================================
void st_test::initTestCase() {
    QVERIFY2(
        !QFile("data.bin").exists() && !QFile("lock").exists(),
        "There should be no data and lock file!"
    );

}

void st_test::cleanupTestCase() {
    QVERIFY2(
        QFile("data.bin").exists() && QFile("lock").exists(),
        "There should be data and lock file!"
    );
    QFile().remove("data.bin");
    QFile().remove("lock");
}

//=================================================
void st_test::cargo_entity_serialization_test() {
    QDataStream stream;
    cargo_entity ent1;
    cargo_entity ent2;

    {
        QFile f("test_file.dat");
        f.open(QIODevice::WriteOnly);
        stream.setDevice(&f);

        ent1 = cargo_entity("test title", 256);
        ent1.serialize(stream);

        stream.setDevice(nullptr);
    }

    {
        QFile f("test_file.dat");
        f.open(QIODevice::ReadOnly);
        stream.setDevice(&f);

        ent2.deserialize(stream);
        f.remove();
    }

    QVERIFY2(
        ent1.id() == ent2.id() && ent1.title() == ent2.title() && ent1.volume() == ent2.volume(),
        "Cargo entity not serialized properly"
    );
}

void st_test::storage_entity_serialization_test() {
    QDataStream stream;
    storage_entity ent1;
    storage_entity ent2;

    {
        QFile f("test_file.dat");
        f.open(QIODevice::WriteOnly);
        stream.setDevice(&f);

        ent1 = storage_entity(128);
        ent1.serialize(stream);

        stream.setDevice(nullptr);
    }

    {
        QFile f("test_file.dat");
        f.open(QIODevice::ReadOnly);
        stream.setDevice(&f);

        ent2.deserialize(stream);
        f.remove();
    }

    QVERIFY2(
        ent1.id() == ent2.id() && ent1.capacity() == ent2.capacity(),
        "Storage entity not serialized properly"
    );
}

void st_test::dpoint_entity_serialization_test() {
    QDataStream stream;
    dpoint_entity ent1;
    dpoint_entity ent2;

    {
        QFile f("test_file.dat");
        f.open(QIODevice::WriteOnly);
        stream.setDevice(&f);

        ent1 = dpoint_entity(0, "some_test_point");
        ent1.serialize(stream);

        stream.setDevice(nullptr);
    }

    {
        QFile f("test_file.dat");
        f.open(QIODevice::ReadOnly);
        stream.setDevice(&f);

        ent2.deserialize(stream);
        f.remove();
    }

    QVERIFY2(
        ent1.id() == ent2.id() && ent1.title() == ent2.title(),
        "Delivery Point entity not serialized properly"
    );
}

void st_test::vessel_entity_serialization_test() {
    QDataStream stream;
    vessel_entity ent1;
    vessel_entity ent2;

    {
        QFile f("test_file.dat");
        f.open(QIODevice::WriteOnly);
        stream.setDevice(&f);

        dpoint_entity test_harbor(0, "test_harbor_for_vessel");
        ent1 = vessel_entity(0, test_harbor.id(), 256);
        ent1.serialize(stream);

        stream.setDevice(nullptr);
    }

    {
        QFile f("test_file.dat");
        f.open(QIODevice::ReadOnly);
        stream.setDevice(&f);

        ent2.deserialize(stream);
        f.remove();
    }

    QVERIFY2(
        ent1.id() == ent2.id() && ent1.harbor() == ent2.harbor() && ent1.capacity() == ent2.capacity(),
        "Delivery Point entity not serialized properly"
    );
}

void st_test::user_entity_serialization_test() {
    QDataStream stream;
    user_entity ent1;
    user_entity ent2;
    QString test_password = "test_password";

    {
        QFile f("test_file.dat");
        f.open(QIODevice::WriteOnly);
        stream.setDevice(&f);

        ent1 = user_entity("test_login", test_password, UserRole::ADMINISTRATOR);
        ent1.serialize(stream);

        stream.setDevice(nullptr);
    }

    {
        QFile f("test_file.dat");
        f.open(QIODevice::ReadOnly);
        stream.setDevice(&f);

        ent2.deserialize(stream);
        f.remove();
    }

    QVERIFY2(
        ent1.id() == ent2.id() && ent1.id() == ent2.id() && ent1.role() == ent2.role() && ent2.verify_password(test_password),
        "User entity not serialized properly"
    );
}

//=================================================
void st_test::user_entity_password_verification_test() {
    QString test_password = "test_password";
    QString wrong_password = "wrong_password";
    user_entity ent1("test_login", test_password, UserRole::ADMINISTRATOR);

    QVERIFY2(
        ent1.verify_password(test_password) || ent1.verify_password(wrong_password),
        "Password verification failed!"
    );
}

void st_test::apparatus_check_null_throws_error() {
    QVERIFY_EXCEPTION_THROWN(apparatus::instance(), std::runtime_error);
}

void st_test::apparatus_check_first_run() {
    apparatus::init();
    QVERIFY(apparatus::instance()->isFirstRun());
    apparatus::shutdown();
}

void st_test::apparatus_check_first_registration() {
    apparatus::init();
    auto as = apparatus::instance()->get_auth_subsystem();

    bool test = as->register_user("testor", "passwd", UserRole::ADMINISTRATOR);
    QVERIFY(test);

    apparatus::shutdown();
}

void st_test::apparatus_check_not_first_run() {
    apparatus::init();
    QVERIFY(!apparatus::instance()->isFirstRun());
    apparatus::shutdown();
}

void st_test::apparatus_check_first_registered_user() {
    apparatus::init();
    auto as = apparatus::instance()->get_auth_subsystem();

    bool test;
    auto user = as->get_user("testor", test);
    QVERIFY(test && user->role() == UserRole::ADMINISTRATOR);

    apparatus::shutdown();
}

void st_test::apparatus_check_remove_user() {
    apparatus::init();
    auto as = apparatus::instance()->get_auth_subsystem();

    bool test = as->remove_user("testor");
    QVERIFY(test);

    apparatus::shutdown();
}

void st_test::object_subsystem_check_add_dpoint() {
    apparatus::init();

    auto os = apparatus::instance()->get_object_subsystem();
    bool test = os->add_dpoint(*this->p);
    QVERIFY(test);

    apparatus::shutdown();
}

void st_test::object_subsystem_check_find_dpoint() {
    apparatus::init();

    auto os = apparatus::instance()->get_object_subsystem();
    bool test;
    os->get_dpoint(this->p->id(), test);
    QVERIFY(test);

    apparatus::shutdown();
}

void st_test::object_subsystem_check_remove_dpoint() {
    apparatus::init();

    auto os = apparatus::instance()->get_object_subsystem();
    bool test = os->remove_dpoint(this->p->id());
    QVERIFY(test);

    apparatus::shutdown();
}

QTEST_APPLESS_MAIN(st_test)

#include "tst_st_test.moc"
