#include <string>

using std::string;

extern const string mainWindowXML = R"(<?xml version="1.0" encoding="UTF-8"?>
<!-- Generated with glade 3.22.1 -->
<interface>
  <requires lib="gtk+" version="3.20"/>
  <object class="GtkWindow" id="MainWindow">
    <property name="can_focus">False</property>
    <property name="title" translatable="yes">Irem</property>
    <property name="default_width">800</property>
    <property name="default_height">600</property>
    <child type="titlebar">
      <placeholder/>
    </child>
    <child>
      <object class="GtkBox">
        <property name="visible">True</property>
        <property name="can_focus">False</property>
        <property name="orientation">vertical</property>
        <child>
          <object class="GtkMenuBar">
            <property name="visible">True</property>
            <property name="can_focus">False</property>
            <child>
              <object class="GtkMenuItem">
                <property name="visible">True</property>
                <property name="can_focus">False</property>
                <property name="label" translatable="yes">_File</property>
                <property name="use_underline">True</property>
                <child type="submenu">
                  <object class="GtkMenu">
                    <property name="visible">True</property>
                    <property name="can_focus">False</property>
                    <child>
                      <object class="GtkMenuItem" id="connect-to">
                        <property name="name">connect-to</property>
                        <property name="visible">True</property>
                        <property name="sensitive">False</property>
                        <property name="can_focus">False</property>
                        <property name="label" translatable="yes">Connect to…</property>
                        <property name="use_underline">True</property>
                      </object>
                    </child>
                    <child>
                      <object class="GtkMenuItem" id="disconnect-from">
                        <property name="name">disconnect-from</property>
                        <property name="visible">True</property>
                        <property name="sensitive">False</property>
                        <property name="can_focus">False</property>
                        <property name="label" translatable="yes">Disconnect from…</property>
                        <property name="use_underline">True</property>
                      </object>
                    </child>
                    <child>
                      <object class="GtkImageMenuItem" id="quit">
                        <property name="label">gtk-quit</property>
                        <property name="visible">True</property>
                        <property name="can_focus">False</property>
                        <property name="use_underline">True</property>
                        <property name="use_stock">True</property>
                      </object>
                    </child>
                  </object>
                </child>
              </object>
            </child>
            <child>
              <object class="GtkMenuItem">
                <property name="visible">True</property>
                <property name="can_focus">False</property>
                <property name="label" translatable="yes">_Edit</property>
                <property name="use_underline">True</property>
                <child type="submenu">
                  <object class="GtkMenu">
                    <property name="visible">True</property>
                    <property name="can_focus">False</property>
                    <child>
                      <object class="GtkImageMenuItem" id="cut">
                        <property name="label">gtk-cut</property>
                        <property name="visible">True</property>
                        <property name="can_focus">False</property>
                        <property name="use_underline">True</property>
                        <property name="use_stock">True</property>
                        <property name="sensitive">False</property>
                      </object>
                    </child>
                    <child>
                      <object class="GtkImageMenuItem">
                        <property name="label">gtk-copy</property>
                        <property name="visible">True</property>
                        <property name="can_focus">False</property>
                        <property name="use_underline">True</property>
                        <property name="use_stock">True</property>
                        <property name="sensitive">False</property>
                      </object>
                    </child>
                    <child>
                      <object class="GtkImageMenuItem">
                        <property name="label">gtk-paste</property>
                        <property name="visible">True</property>
                        <property name="can_focus">False</property>
                        <property name="use_underline">True</property>
                        <property name="use_stock">True</property>
                        <property name="sensitive">False</property>
                      </object>
                    </child>
                    <child>
                      <object class="GtkImageMenuItem">
                        <property name="label">gtk-delete</property>
                        <property name="visible">True</property>
                        <property name="can_focus">False</property>
                        <property name="use_underline">True</property>
                        <property name="use_stock">True</property>
                        <property name="sensitive">False</property>
                      </object>
                    </child>
                    <child>
                      <object class="GtkSeparatorMenuItem">
                        <property name="visible">True</property>
                        <property name="can_focus">False</property>
                      </object>
                    </child>
                    <child>
                      <object class="GtkMenuItem" id="worlds">
                        <property name="name">edit-worlds</property>
                        <property name="visible">True</property>
                        <property name="can_focus">False</property>
                        <property name="label" translatable="yes">Worlds</property>
                        <property name="use_underline">True</property>
                      </object>
                    </child>
                    <child>
                      <object class="GtkMenuItem" id="avatars">
                        <property name="name">edit-avatars</property>
                        <property name="visible">True</property>
                        <property name="sensitive">False</property>
                        <property name="can_focus">False</property>
                        <property name="label" translatable="yes">Avatars</property>
                        <property name="use_underline">True</property>
                      </object>
                    </child>
                  </object>
                </child>
              </object>
            </child>
            <child>
              <object class="GtkMenuItem">
                <property name="visible">True</property>
                <property name="can_focus">False</property>
                <property name="label" translatable="yes">_Help</property>
                <property name="use_underline">True</property>
                <child type="submenu">
                  <object class="GtkMenu">
                    <property name="visible">True</property>
                    <property name="can_focus">False</property>
                    <child>
                      <object class="GtkImageMenuItem">
                        <property name="label">gtk-about</property>
                        <property name="visible">True</property>
                        <property name="can_focus">False</property>
                        <property name="use_underline">True</property>
                        <property name="use_stock">True</property>
                      </object>
                    </child>
                  </object>
                </child>
              </object>
            </child>
          </object>
          <packing>
            <property name="expand">False</property>
            <property name="fill">True</property>
            <property name="position">0</property>
          </packing>
        </child>
        <child>
          <object class="GtkNotebook" id="notebook">
            <property name="visible">True</property>
            <property name="can_focus">True</property>
          </object>
          <packing>
            <property name="expand">True</property>
            <property name="fill">True</property>
            <property name="position">1</property>
          </packing>
        </child>
      </object>
    </child>
  </object>
</interface>
)";