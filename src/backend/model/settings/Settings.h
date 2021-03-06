// Pegasus Frontend
// Copyright (C) 2017  Mátyás Mustoha
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.


#pragma once

#include "AppSettings.h"
#include "KeyEditor.h"
#include "LocaleList.h"
#include "ThemeList.h"
#include "ProviderList.h"

#include <QObject>


namespace model {

/// Provides a settings interface for the frontend layer
class Settings : public QObject {
    Q_OBJECT

    Q_PROPERTY(bool fullscreen
               READ fullscreen WRITE setFullscreen
               NOTIFY fullscreenChanged)
    Q_PROPERTY(model::KeyEditor* keyEditor READ keyEditorPtr NOTIFY keysChanged)
    Q_PROPERTY(model::LocaleList* locales READ localesPtr CONSTANT)
    Q_PROPERTY(model::ThemeList* themes READ themesPtr CONSTANT)
    Q_PROPERTY(model::ProviderList* providers READ providersPtr CONSTANT)
    Q_PROPERTY(QStringList gameDirs READ gameDirs NOTIFY gameDirsChanged)

public:
    explicit Settings(QObject* parent = nullptr);

    bool fullscreen() const { return AppSettings::general.fullscreen; }
    void setFullscreen(bool);

    QStringList gameDirs() const;
    KeyEditor* keyEditorPtr() { return &m_key_editor; }
    LocaleList* localesPtr() { return &m_locales; }
    ThemeList* themesPtr() { return &m_themes; }
    ProviderList* providersPtr() { return &m_providers; }

    Q_INVOKABLE void addGameDir(const QString&);
    Q_INVOKABLE void removeGameDirs(const QVariantList&);

signals:
    void fullscreenChanged();
    void gameDirsChanged();
    void keysChanged();

private:
    KeyEditor m_key_editor;
    LocaleList m_locales;
    ThemeList m_themes;
    ProviderList m_providers;
};

} // namespace model
