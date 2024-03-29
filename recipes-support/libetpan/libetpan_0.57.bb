DESCRIPTION = "libetpan is a library for communicating with mail and news servers. \
It supports the protocols SMTP, POP3, IMAP and NNTP."
HOMEPAGE = "http://www.etpan.org"
SECTION = "libs"
DEPENDS = "gnutls"
LICENSE = "BSD"
PR = "r1"

SRC_URI = "${SOURCEFORGE_MIRROR}/libetpan/libetpan-${PV}.tar.gz \
	   file://libetpan-autoreconf.patch \
           file://libetpan-ldflags.patch"

inherit autotools pkgconfig gettext binconfig

LIC_FILES_CHKSUM = "file://COPYRIGHT;md5=f18ebe7e452708c26f83954f81062ba7 \
                    file://src/engine/mailengine.c;beginline=7;endline=29;md5=2cb1057a004588965254de2eee0b15a6"

EXTRA_OECONF = "--without-openssl --with-gnutls --disable-db"

PARALLEL_MAKE = ""

FILES_${PN} = "${libdir}/lib*.so.*"
FILES_${PN}-dev = "${bindir} ${includedir} ${libdir}/lib*.so ${libdir}/*.la ${libdir}/*.a ${libdir}/pkgconfig"


SRC_URI[md5sum] = "8ce8c6c071e81884a475b12b7f9a9cc0"
SRC_URI[sha256sum] = "1f3fda5c9e2961d1a6298dc8aadae321493d37727d8db45bc2e8d58f20547011"
