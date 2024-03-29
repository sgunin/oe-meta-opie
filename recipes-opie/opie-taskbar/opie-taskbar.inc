DESCRIPTION = "Opie Launcher and Taskbar"
SECTION = "opie/base"
LICENSE = "GPLv2"
# FIXME stopgap until split archives have license files included
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"
DEPENDS = "opie-libqrsync opie-qss"
# Unfortunately, ipkg has buggy handling of Rdepends to multiple packages with the same Provides.
# Instead of seeing if something in package package lists selects needed package among the rest
# or errors out otherwise, it just install random package which has needed Provides. So, comment
# this out.
#RDEPENDS_${PN} = "opie-taskbar-images"
APPNAME = "qpe"

S = "${WORKDIR}/launcher"

inherit opie

do_configure_prepend() {
        ln -s ${WORKDIR}/calibrate ${S}/calibrate
        ln -s ${WORKDIR}/mediummount ${S}/mediummount
}

SECTIONS = "1Pim Applications Examples Games Opie-SH Python Settings"
PICS = "opielogo32x32.png start_button.png new_wait.png opielogo16x16.png sidebar.png"

do_install() {
        install -d ${D}${bindir}
        for i in ${SECTIONS}
        do
                install -d ${D}${palmtopdir}/apps/$i/
                install -m 0644 ${WORKDIR}/apps/$i/.directory ${D}${palmtopdir}/apps/$i/
        done
        install -d ${D}${palmtopdir}/pics/launcher
        install -d ${D}${palmtopdir}/pics/logo
        install -d ${D}${palmtopdir}/pics/RoH/star/
        install -d ${D}${palmtopdir}/etc/colors
        install -d ${D}${palmtopdir}/etc/skel
        install -d ${D}${sysconfdir}

        install -m 0755 ${S}/qpe ${D}${bindir}/qpe
        install -m 0644 ${WORKDIR}/apps/Settings/calibrate.desktop ${D}${palmtopdir}/apps/Settings/
        install -m 0644 ${WORKDIR}/apps/Settings/quit.desktop ${D}${palmtopdir}/apps/Settings/

        for p in ${PICS}
        do
                install -m 0644 ${WORKDIR}/pics/launcher/$p ${D}${palmtopdir}/pics/launcher/$p
        done

        install -m 0644 ${WORKDIR}/pics/logo/*.* ${D}${palmtopdir}/pics/logo/
        install -m 0644 ${WORKDIR}/pics/RoH/star/*.png ${D}${palmtopdir}/pics/RoH/star/

        install -m 0644 ${WORKDIR}/etc/colors/*.scheme ${D}${palmtopdir}/etc/colors/
        install -m 0644 ${WORKDIR}/etc/mime.types ${D}${sysconfdir}/

        install -m 0644 ${WORKDIR}/pics/capslock.xpm ${D}${palmtopdir}/pics/
        install -m 0644 ${WORKDIR}/pics/numlock.xpm ${D}${palmtopdir}/pics/

        install -d ${D}${includedir}
        install obexinterface.h ${D}${includedir}/
        
        install -d ${D}${sysconfdir}/apm/event.d/
        install -m 0755 ${WORKDIR}/etc/03opiesignal ${D}${sysconfdir}/apm/event.d/
        install -m 0644 ${WORKDIR}/etc/opie_sysevents.conf ${D}${sysconfdir}/
}

FILES_opie-taskbar_append = " ${sysconfdir} ${palmtopdir}/apps ${palmtopdir}/pics"
