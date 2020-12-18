#include <QtTest>

#include "../sea_transport/entities/cargo_entity.h"
#include "../sea_transport/entities/storage_entity.h"
#include "../sea_transport/entities/dpoint_entity.h"
#include "../sea_transport/entities/vessel_entity.h"
#include "../sea_transport/entities/user_entity.h"

#include "../sea_transport/system/apparatus.h"

#include <QFile>
#include <QDataStream>

class st_test : public QObject
{
    Q_OBJECT

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
    void apparatus_check_auth_subsystem();
    void apparatus_check_object_subsystem();
};

st_test::st_test() {

}

st_test::~st_test() {

}

//=================================================
void st_test::initTestCase() {
    QVERIFY2(
        !QFile("data.bin").exists(),
        "There should be no data file!"
    );
}

void st_test::cleanupTestCase() {
    QVERIFY2(
        QFile("data.bin").exists(),
        "There should be a data file!"
    );
    QFile().remove("data.bin");
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

        ent1 = dpoint_entity("some_test_point");
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

        dpoint_entity test_harbor("test_harbor_for_vessel");
        ent1 = vessel_entity(test_harbor, 256);
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
        ent1.id() == ent2.id() && ent1.harbor().id() == ent2.harbor().id() && ent1.capacity() == ent2.capacity(),
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
    QVERIFY2(
        apparatus::instance()->isFirstRun(),
        "Not a first run!"
    );
    apparatus::shutdown();
}

void st_test::apparatus_check_auth_subsystem() {
    apparatus::init();
    auth_system as = apparatus::instance()->get_auth_subsystem();
    {
        bool test = as.register_user("testor", "passwd", UserRole::ADMINISTRATOR);
        QVERIFY(test);
    }
    {
        bool test;
        as.get_user("testor", test);
        QVERIFY(test);
    }
    {
        bool test = as.remove_user("testor");
        QVERIFY(test);
    }
    apparatus::shutdown();
}

void st_test::apparatus_check_object_subsystem() {
    apparatus::init();
    object_system os = apparatus::instance()->get_object_subsystem();
    dpoint_entity p("test");
    {
        bool test = os.add_dpoint(p);
        QVERIFY(test);
    }
    {
        bool test;
        os.get_dpoint(p.id(), test);
        QVERIFY(test);
    }
    {
        bool test = os.remove_dpoint(p.id());
        QVERIFY(test);
    }
    apparatus::shutdown();
}

QTEST_APPLESS_MAIN(st_test)

#include "tst_st_test.moc"
