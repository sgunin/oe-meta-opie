DESCRIPTION = "Gnuplot is a portable command-line driven interactive datafile \
(text or binary) and function plotting utility."
HOMEPAGE = "http://www.gnuplot.info/"
SECTION = "console/scientific"
LICENSE = "BSD-4"
DEPENDS = "virtual/libx11 gd cairo readline"

inherit autotools

acpaths = ""

EXTRA_OECONF = "--with-readline=${STAGING_LIBDIR}/.. \
		--without-lisp-files \
		--without-tutorial \
                --disable-wxwidgets"

do_compile_prepend() {
	install -m 0644 ${WORKDIR}/qtplot-0.2/qtopia.trm ${S}/term/
}

do_install_append() {
	install -d ${D}${datadir}/applications/
	install -m 0644 ${WORKDIR}/gnuplot.desktop ${D}${datadir}/applications/
	install -d ${D}${datadir}/pixmaps/
	install -m 0644 ${WORKDIR}/gnuplot.png ${D}${datadir}/pixmaps/
}

PACKAGES =+ "${PN}-x11-dbg ${PN}-x11"
DESCRIPTION_${PN}-x11 = "X11 display terminal for Gnuplot."
SECTION_${PN}-x11 = "x11/scientific"
FILES_${PN}-x11 = "${libexecdir} ${datadir}/applications ${datadir}/pixmaps ${libdir}/X11 "

FILES_${PN} += "${datadir}/texmf"
FILES_${PN}-x11-dbg += "${libexecdir}/gnuplot/*/.debug"
