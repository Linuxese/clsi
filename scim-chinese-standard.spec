Name:           scim-chinese-standard
Version:        0.0.2
Release:        1%{?dist}
Summary:  SCIM support for Input Method specification of Chinese Linux Standard

Group:          System Environment/Libraries
License:        LGPL
URL:            https://sourceforge.net/projects/clsi
Source0:        http://dl.sourceforge.net/sourceforge/clsi/%{name}-%{version}.tar.gz
BuildRoot:      %{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n)

BuildRequires:  scim-devel
Requires:       scim

%description
This is an adapter to allow SCIM to interoperate with the Input Method
specification of the Chinese Linux Standard.

%prep
%setup -q


%build
%configure --disable-static
make %{?_smp_mflags}


%install
rm -rf $RPM_BUILD_ROOT
make install DESTDIR=$RPM_BUILD_ROOT

rm $RPM_BUILD_ROOT/%{_libdir}/scim-1.0/*/*.la

mkdir -p $RPM_BUILD_ROOT/%{_libdir}/chinese-standard/{ime,helper}


%clean
rm -rf $RPM_BUILD_ROOT


%files
%defattr(-,root,root,-)
%doc AUTHORS COPYING NEWS README ChangeLog
%dir %{_libdir}/scim-1.0/IMEngine
%{_libdir}/scim-1.0/IMEngine/chinese-standard-im.so
%dir %{_libdir}/scim-1.0/Helper
%{_libdir}/scim-1.0/Helper/chinese-standard-helper.so
%dir %{_libdir}/chinese-standard/helper
%dir %{_libdir}/chinese-standard/ime



%changelog
* Thu Jul 13 2006 Qingyu Wang <qwang@redhat.com> 0.0.2-1
- Remove parameters of two functions because of the change of standard

* Tue Jul 11 2006 Qingyu Wang <qwang@redhat.com> 0.0.1-1
- Package for Fedora Extras (#197559)

* Mon Jul 10 2006 Qingyu Wang <qwang@redhat.com> 0.0.1-0.3
- Modify the spec file
- Change standard-*.so to chinese-standard-*.so

* Wed Jun 01 2006 Qingyu Wang <qwang@redhat.com> 0.0.1-0.1
- Initial packaging of scim-chinese-standard

* Tue Mar 07 2006 Qingyu Wang <qwang@redhat.com>
- First release of scim-standard-helper
- Added helper functions for scim-standard-im
- First release of scim-standard-im
