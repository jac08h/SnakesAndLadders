TEMPLATE = subdirs
# build the project sequentially as listed in SUBDIRS
CONFIG+= ordered

SUBDIRS += \
    src \
    app \

app.depends = src

OTHER_FILES += \
    defaults.pri
