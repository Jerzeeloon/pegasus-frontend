TEMPLATE = subdirs

SUBDIRS += \
    collection \
    game \
    gameassets \
    localelist \
    system \
    themelist \

# Proper QML testing was added in 5.11
!lessThan(QT_MAJOR_VERSION, 5): !lessThan(QT_MINOR_VERSION, 11) {
    SUBDIRS += \
        keyeditor
}
