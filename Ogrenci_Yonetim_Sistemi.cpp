#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <fstream>

struct Ogrenci {
    std::string adSoyad;
    int numara;
    double ortalama ;

};

bool numaraVarMi(const std::vector<Ogrenci>& ogrenciler, int numara) {
    for (const auto& ogr : ogrenciler) {
        if (ogr.numara == numara) {
            return true;
        }
    }
    return false;
}

void OgrEkle(std::vector<Ogrenci>& ogrenciler) {
    int girisKontrol = -1;
    do {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        Ogrenci ogrenci;
        bool basariliGiris = false;

        // Ad Soyad girişi
        std::cout << "Eklenecek öğrencinin adını ve soyadını giriniz: " << std::endl;
        std::getline(std::cin,ogrenci.adSoyad);

        // Öğrenci numarası girişi ve kontrolü
        std::cout << "Öğrencinin numarasını giriniz: " << std::endl;
        if (!(std::cin >> ogrenci.numara) || ogrenci.numara <= 0) {
            std::cout << "Numara pozitif bir tam sayı olmalıdır!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (numaraVarMi(ogrenciler, ogrenci.numara)) { // Benzersizlik kontrolü
            std::cout << "Hata: Bu numara zaten kayıtlı!" << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Buffer'ı temizle
        } else {
            // Ortalama girişi ve kontrolü
            std::cout << "4'lük sisteme göre öğrencinin ortalamasını giriniz: " << std::endl;
            if (!(std::cin >> ogrenci.ortalama) || ogrenci.ortalama <= 0 || ogrenci.ortalama > 4) {
                std::cout << "Hatalı Giriş!" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                ogrenciler.push_back(ogrenci);
                basariliGiris = true;
            }
        }
        // Hatalı veya başarılı girişten sonra devam kontrolü için buffer temizliği
        if (!basariliGiris) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cout << "Öğrenci ekleme işlemine devam etmek için 1'i, durmak için 0'ı tuşlayınız: " << std::endl;
        if (!(std::cin >> girisKontrol)) {
            girisKontrol = 0;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (girisKontrol != 0);
}

void OgrSil(std::vector<Ogrenci>& ogrenciler) {
    int girisKontrol = -1;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    do {
        Ogrenci ogrenci;
        bool bulundu = false;
        int aranacakNumara;

        // Öğrenci numarası girişi ve kontrolü
        std::cout << "Silinecek öğrencinin numarasını giriniz: " << std::endl;
        if (!(std::cin >> aranacakNumara) || 0 >= aranacakNumara) {
            std::cout << "Hatalı numara girişi!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            for (int i = 0; i < ogrenciler.size(); i++) {
                if (ogrenciler[i].numara == aranacakNumara) {
                    std::cout << ogrenciler[i].adSoyad << " adlı öğrenci silindi!" << std::endl;
                    ogrenciler.erase(ogrenciler.begin() + i);
                    bulundu = true;
                    i--; // Silme işleminden sonra indeksi bir geri al
                }
            }
            if (!bulundu) {
                std::cout << "Girilen numaraya sahip öğrenci bulunamadı!" << std::endl;
            }
        }
        std::cout << "Öğrenci silme işlemine devam etmek için 1'i, durmak için 0'ı tuşlayınız: " << std::endl;
        if (!(std::cin >> girisKontrol)) {
            girisKontrol = 0;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (girisKontrol != 0);
}

void OgrIslemleri(std::vector<Ogrenci>& ogrenciler) {
    int secim = 0;
    std::cout << "\n1. Yeni Öğrenci Ekle," << std::endl;
    std::cout << "2. Kayıtlı Öğrenci Sil," << std::endl;
    std::cout << "Yapılacak işlemi seçiniz: " << std::endl;
    if (!(std::cin >> secim) || secim < 0 || secim > 2) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Hatalı Giriş!" << std::endl;
    }
    if (secim == 1) {
        OgrEkle(ogrenciler);
    } else if (secim == 2) {
        OgrSil(ogrenciler);
    }
}

void listele(const Ogrenci* ilkOgrenci, int ogrSayisi) {
    for (int i = 0; i < ogrSayisi; i++) {
        std::cout << i + 1 << ". "
                  << ilkOgrenci[i].numara << " - "
                  << ilkOgrenci[i].adSoyad << " (Ortalama: "
                  << ilkOgrenci[i].ortalama << ")"
                  << std::endl;
    }
}

const Ogrenci* ara(const Ogrenci* ogrenciler, int boyut, int aranacakNumara) {
    for (int i = 0; i < boyut; i++) {
        if (ogrenciler[i].numara == aranacakNumara) {
            // Öğrenci Bulundu: Gösterici aritmetiği ile adresi döndür.
            return ogrenciler + i;
        }
    }
    // Bulunamadı: Döngü bitti ve öğrenci bulunamadı.
    return nullptr;
}

const Ogrenci* enBasarili(const Ogrenci* ogrenciler, int boyut) {
    if (boyut == 0) {
        return nullptr; // Dizi boşsa nullptr döndür.
    }
    const Ogrenci* enBasariliOgr = ogrenciler;

    for (int i = 1; i < boyut; i++) {
        if (ogrenciler[i].ortalama > enBasariliOgr->ortalama) {
            enBasariliOgr = ogrenciler + i;
        }
    }
    return enBasariliOgr;
}

void ortalamaAltinda(const Ogrenci* ogrenciler, int boyut, double esikOrtalama) {
    std::cout << "\n--- Ortalaması " << esikOrtalama << " altında olan öğrenciler ---" << std::endl;
    bool bulundu = false; // Hiç öğrenci bulunup bulunmadığını kontrol etmek için

    for (int i = 0; i < boyut; i++) {
        // Öğrencinin ortalaması esikOrtalama'dan küçük mü?
        if (ogrenciler[i].ortalama < esikOrtalama) {
            std::cout << ogrenciler[i].adSoyad << " Ortalama: " << ogrenciler[i].ortalama << std::endl;
            bulundu = true;
        }
    }
    if (!bulundu) {
        std::cout << "Belirtilen ortalamanın altında öğrenci bulunmamaktadır." << std::endl;
    }
}

void bubbleSort(std::vector<Ogrenci>& ogrenciler) {
    if (ogrenciler.size() == 0) { // Öğrenci listesi boşsa
        std::cout << "Sıralanacak öğrenci bulunmamaktadır." << std::endl;
        return;
    }
    for (int i = 0; i < ogrenciler.size(); i++) {
        for (int j = 0; j < ogrenciler.size() - i - 1; j++) {
            if (ogrenciler[j].ortalama > ogrenciler[j+1].ortalama) {
                std::swap(ogrenciler[j], ogrenciler[j+1]);
            }
        }
    }
    std::cout << "Listenin Ortalamaya göre sıralanmış hali: (artan sırada)" << std::endl;
    listele(ogrenciler.data(), ogrenciler.size());
}

void DosyayaYaz(const std::vector<Ogrenci>& ogrenciler, const std::string& dosyaAdi) {
    std::ofstream dosya(dosyaAdi); // Dosya açma
    if (!dosya.is_open()) { // Dosya açılamazsa
        std::cout << "Dosya açılamadı!" << std::endl;
    } else {
        for (const auto& ogrenci : ogrenciler) {
            dosya << ogrenci.numara << "," << ogrenci.adSoyad
            << "," << ogrenci.ortalama << std::endl; // CSV formatında yazılır
        }
        dosya.close();
        std::cout << "Öğrenciler dosyaya yazıldı: " << dosyaAdi << std::endl;
    }
}

// Menü oluşturulur, kullanıcıdan seçim girdisi istenir ve girdi için hata kontrolü yapılır.
void menu(std::vector<Ogrenci>& ogrenciler) {
    int secim = 0;
    do {
        std::cout << "\n---------------MENU---------------" << std::endl;
        std::cout << "1. Öğrenci İşlemleri (Ekle/Sil)" << std::endl;
        std::cout << "2. Tüm öğrencileri listele" << std::endl;
        std::cout << "3. Belirli bir numaraya göre öğrenci ara" << std::endl;
        std::cout << "4. En yüksek ortalamalı öğrenciyi bul" << std::endl;
        std::cout << "5. Ortalaması 3.0’ın altında olan öğrencileri göster" << std::endl;
        std::cout << "6. Öğrencileri ortalamalarına göre sırala" << std::endl;
        std::cout << "7. Verileri dosyaya kaydet" << std::endl;
        std::cout << "8. Çıkış\n" << std::endl;
        std::cout << "Lütfen yapılacak işlemin yanındaki rakamı tuşlayınız:" << std::endl;
        if (!(std::cin >> secim) || secim < 1 || secim > 8) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\n Hatalı Giriş! \n Tekrar Deneyin" << std::endl;
            continue;
        }
        if (secim == 1) {
            OgrIslemleri(ogrenciler);
        } else if (secim == 2) {
            listele(ogrenciler.data(), ogrenciler.size());
        } else if (secim == 3) {
            int aranacakNumara;
            std::cout << "Aranacak numarayı giriniz: " << std::endl;
            std::cin >> aranacakNumara;
            const Ogrenci* bulunanOgrenci = ara(ogrenciler.data(), ogrenciler.size(), aranacakNumara);

            if (bulunanOgrenci != nullptr) {
                std::cout << "Öğrenci bulundu! Numara: " << bulunanOgrenci->numara
                << " Ad:" << bulunanOgrenci->adSoyad << " Ortalama:" << bulunanOgrenci->ortalama << std::endl;
            } else {
                std::cout << "Hata: Belirtilen numarada öğrenci bulunamadı." << std::endl;
            }
        } else if (secim == 4) {
            const Ogrenci* enBasariliOgr = enBasarili(ogrenciler.data(), ogrenciler.size());

            if (enBasariliOgr != nullptr) {
                std::cout << "\nEn başarılı öğrenci: " << std::endl;
                std::cout << enBasariliOgr->adSoyad << ", Ortalama: " << enBasariliOgr->ortalama << std::endl;
            } else {
                std::cout << "Listede hiç öğrenci yok." << std::endl;
            }
        } else if (secim == 5) {
            ortalamaAltinda(ogrenciler.data(), ogrenciler.size(), 3.0);
        } else if (secim == 6) {
            bubbleSort(ogrenciler);
        } else if (secim == 7) {
            std::string dosyaAdi = "ogrenciler.txt";
            DosyayaYaz(ogrenciler, dosyaAdi);
        }
        // Çıkış (seçim 8) haricindeki işlemlerden sonra buffer temizliği
        if (secim != 8) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }while (secim != 8);
}

int main() {
    std::vector<Ogrenci> ogrenciler = { // öğrenci nesnelerinin tutulacağı vektör
        {"Mehmet Yılmaz", 205, 3.02},
        {"Rıdvan Çakır", 206, 2.12},
        {"Ayşe Demir", 207, 3.35},
        {"Mert Kılıç", 208, 2.92},
        {"Zeynep Aydın", 209, 1.45}
    };
    menu(ogrenciler);
    std::cout << "Programdan çıkılyor. İyi günler!" << std::endl;
    return 0;
}
