#pragma once

#include <QAbstractListModel>

class UsersModel : public QAbstractListModel
{
public:
        enum Roles
        {
                AvatarUrl = Qt::UserRole,
                DisplayName,
                UserID,
        };

        UsersModel(const std::string &roomId, QObject *parent = nullptr);
        QHash<int, QByteArray> roleNames() const override;
        int rowCount(const QModelIndex &parent = QModelIndex()) const override
        {
                (void)parent;
                return roomMembers_.size();
        }
        QVariant data(const QModelIndex &index, int role) const override;

private:
        std::string room_id;
        std::vector<std::string> roomMembers_;
        std::vector<QString> displayNames;
        std::vector<QString> userids;
};
