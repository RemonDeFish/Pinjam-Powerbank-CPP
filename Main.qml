import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    width: 450
    height: 650
    visible: true
    title: "PPBank - Peminjaman Powerbank"
    color: "#f0f9ff"

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 30
        spacing: 20

        // Judul Aplikasi
        Text {
            text: "Peminjaman Powerbank"
            font.pixelSize: 24
            font.bold: true
            color: "#1e3a8a"
            Layout.alignment: Qt.AlignHCenter
            Layout.bottomMargin: 10
        }

        // Kartu Form Input
        Rectangle {
            Layout.fillWidth: true
            implicitHeight: 220
            color: "white"
            radius: 12
            border.color: "#bfdbfe"
            border.width: 1

            GridLayout {
                anchors.fill: parent
                anchors.margins: 20
                columns: 2
                rowSpacing: 15
                columnSpacing: 15

                Text { text: "Nama Lengkap"; color: "#475569"; font.pixelSize: 14 }
                TextField {
                    id: inputNama
                    placeholderText: "Masukkan nama..."
                    Layout.fillWidth: true
                }

                Text { text: "NIM / NPM"; color: "#475569"; font.pixelSize: 14 }
                TextField {
                    id: inputNim
                    placeholderText: "Masukkan angka..."
                    Layout.fillWidth: true
                }

                Text { text: "Pilih Unit"; color: "#475569"; font.pixelSize: 14 }
                ComboBox {
                    id: comboPowerbank
                    model: ["PB01 - 10000 mAh", "PB02 - 10000 mAh", "PB03 - 20000 mAh"]
                    Layout.fillWidth: true
                }
            }
        }

        // Tombol Pinjam Modern
        Button {
            id: btnPinjam
            text: "Pinjam Sekarang"
            font.bold: true
            Layout.fillWidth: true
            Layout.preferredHeight: 45

            background: Rectangle {
                color: btnPinjam.down ? "#1d4ed8" : "#2563eb"
                radius: 8
            }
            contentItem: Text {
                text: btnPinjam.text
                font: btnPinjam.font
                color: "white"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            // Logika Klik (Tersambung ke C++)
            onClicked: {
                let nama = inputNama.text;
                let nim = inputNim.text;
                let pb = comboPowerbank.currentText;

                if(nama !== "" && nim !== "") {
                    // Memanggil fungsi C++ dari LoanManager
                    let hasilLog = backend.tambahPinjaman(nama, nim, pb);

                    kotakHasil.append("✓ " + hasilLog);

                    // Reset input
                    inputNama.text = "";
                    inputNim.text = "";
                } else {
                    kotakHasil.append("⚠ Gagal: Nama dan NIM harus diisi!");
                }
            }
        }

        // Kartu Output Hasil
        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "white"
            radius: 12
            border.color: "#bfdbfe"
            border.width: 1

            ScrollView {
                anchors.fill: parent
                anchors.margins: 10
                clip: true

                TextArea {
                    id: kotakHasil
                    readOnly: true
                    color: "#334155"
                    font.pixelSize: 14
                    placeholderText: "Riwayat peminjaman akan tampil di sini..."
                    background: null
                }
            }
        }
    }
}