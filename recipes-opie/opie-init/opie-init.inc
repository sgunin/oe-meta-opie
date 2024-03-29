DESCRIPTION = "Opie Startup scripts and config"
SECTION = "opie/base"
LICENSE = "GPLv2"
# FIXME stopgap until split archives have license files included
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"
#APPNAME = "qpe"

#S = "${WORKDIR}/launcher"

#inherit opie
inherit update-rc.d

INITSCRIPT_NAME = "opie"
INITSCRIPT_PARAMS = "start 99 5 . stop 20 0 1 6 ."

do_install() {
	install -d ${D}${sysconfdir}/init.d
	install -d ${D}${sysconfdir}/profile.d	
	install -d ${D}${bindir}
	install -d ${D}${palmtopdir}/etc/skel

	sed -s "s|@palmtopdir@|${palmtopdir}|" ${WORKDIR}/opie >${WORKDIR}/opie.tmp
	sed -s "s|@palmtopdir@|${palmtopdir}|" ${WORKDIR}/opie_defaults >${WORKDIR}/opie_defaults.tmp
	install -m 0755 ${WORKDIR}/opie.tmp ${D}${sysconfdir}/init.d/opie
	install -m 0644 ${WORKDIR}/opie_defaults.tmp ${D}${sysconfdir}/profile.d/opie_defaults

	install -m 0755 ${WORKDIR}/opie-reorgfiles ${D}${bindir}/
	install -m 0644 ${WORKDIR}/qpe.conf ${D}${palmtopdir}/etc/skel/

	if [ -s ${WORKDIR}/locale.conf ]; then
	    install -m 0644 ${WORKDIR}/locale.conf ${D}${palmtopdir}/etc/skel/
	fi

# This should not be necessary anymore (w100 is currently disabled for c7x0)
#	case ${MACHINE} in
#	c7x0)
#		install -d ${D}${sysconfdir}/apm/event.d/
#		install -m 0755 ${WORKDIR}/qpe-suspend-resume ${D}${sysconfdir}/apm/event.d/00-qpe-suspend-resume.sh
#                ;;
#        *)
#                ;;
#        esac	
}

#FILES_opie-init_append = " ${sysconfdir} ${palmtopdir}/bin"
FILES_${PN} += "${palmtopdir}"

PACKAGE_ARCH = "${MACHINE_ARCH}"
