DESCRIPTION = "User Interface Generator and Meta Object Compiler (moc) for Qt(E) 2.x"
HOMEPAGE = "http://www.trolltech.com"
SECTION = "devel"
LICENSE = "GPLv2 | QPL"
PR = "r6"

SRC_URI = "ftp://ftp.trolltech.com/pub/qt/source/qt-embedded-${PV}-free.tar.gz \
           file://fix-makefile.patch \
           file://gcc3_4.patch \
           file://gcc4.patch \
           file://gcc4_1.patch \
           file://64bit-cleanup.patch \
	   file://kernel-asm-page.patch"
S = "${WORKDIR}/qt-${PV}"

LIC_FILES_CHKSUM = "file://LICENSE.GPL;md5=aea7d119b7f7d798464fa2b1aae005f8 \
                    file://README;beginline=1;endline=7;md5=d3e237af71522cc2a3c89dbaf48b345d"

inherit qmake_base
BBCLASSEXTEND = "native nativesdk"
UICMOCNATIVE = "uicmoc-native"
UICMOCNATIVE_virtclass-native = ""
DEPENDS_prepend = "${UICMOCNATIVE}"

export QTDIR = "${S}"
SYSUICMOC = 'SYSCONF_MOC="${STAGING_BINDIR_NATIVE}/moc2" SYSCONF_UIC="${STAGING_BINDIR_NATIVE}/uic2"'
SYSUICMOC_virtclass-native = ""
EXTRA_OEMAKE = 'SYSCONF_CC="${CC}" SYSCONF_CXX="${CXX}" SYSCONF_CFLAGS="${CFLAGS}" SYSCONF_CXXFLAGS="${CXXFLAGS} -DQWS" SYSCONF_LINK="${CXX}" ${SYSUICMOC}'

QT_CONFIG_FLAGS = "-depths 8,16 -no-qvfb -no-g++-exceptions -no-jpeg -no-mng \
                   -qt-zlib -qt-libpng -no-xft -no-xkb -no-vnc -no-sm \
                   -no-opengl -static -qconfig oe"

do_configure() {
    touch src/tools/qconfig-oe.h
    echo "#define QT_NO_FREETYPE" >> src/tools/qconfig-oe.h
    echo yes | ./configure ${QT_CONFIG_FLAGS} || die "Configuring qt failed"
}

do_compile() {
    oe_runmake symlinks   || die "Can't symlink include files"
    oe_runmake -C src/moc || die "Building moc failed"

    cp src/moc/moc bin/

    oe_runmake -C src                 || die "Building libqt.a failed"
    oe_runmake -C tools/designer/util || die "Building libqutil.a failed"
    oe_runmake -C tools/designer/uic  || die "Building uic failed"
    oe_runmake -C tools/qvfb          || die "Building qvfb failed"
    oe_runmake -C tools/makeqpf       || die "Building makeqpf failed"
}

do_install() {
    install -d ${D}${bindir}
    install -m 0755 bin/moc ${D}${bindir}/moc2
    install -m 0755 bin/uic ${D}${bindir}/uic2
    install -m 0755 tools/qvfb/qvfb ${D}${bindir}/qvfb2
    install -m 0755 tools/makeqpf/makeqpf ${D}${bindir}
}

SRC_URI[md5sum] = "1f7ad30113afc500cab7f5b2f4dec0d7"
SRC_URI[sha256sum] = "883363eb0c94de3d1e36f3ab9e09a8f127418d497213cc1a0ed1a1588ecd66b8"

NATIVE_INSTALL_WORKS = "1"
