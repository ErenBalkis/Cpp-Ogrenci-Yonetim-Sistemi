# 🎓 Cpp-Ogrenci-Yonetim-Sistemi (C++ Öğrenci Yönetim Sistemi)

Bu proje, C++ dilinde yazılmış basit bir konsol tabanlı **Öğrenci Veri Arama ve Raporlama Uygulamasıdır**. Uygulama, öğrenci kayıtlarını yönetmek, listelemek, aramak, sıralamak ve dosya olarak kaydetmek için temel işlevler sunar.

## ✨ Özellikler

Uygulama, standart C++ kütüphaneleri (`iostream`, `vector`, `fstream` vb.) kullanılarak geliştirilmiştir.

* **Öğrenci İşlemleri:** Yeni öğrenci ekleme (`OgrEkle`) ve kayıtlı öğrenci silme (`OgrSil`).
    * Öğrenci numarası girişi için benzersizlik ve pozitif tam sayı kontrolü yapılır.
* **Listeleme ve Raporlama:**
    * Tüm kayıtlı öğrencileri listeleme.
    * Ortalaması 3.0'ın altında olan öğrencileri gösterme.
    * En yüksek ortalamalı öğrenciyi bulma.
* **Arama:** Belirli bir öğrenci numarasına göre kayıt arama (`ara`).
* **Sıralama:** Öğrencileri ortalamalarına göre (artan sırada) sıralama (`bubbleSort`).
* **Veri Kayıt:** Tüm öğrenci verilerini `.txt` dosyasına (CSV formatında) kaydetme (`DosyayaYaz`).

## 🛠️ Nasıl Derlenir ve Çalıştırılır?

Bu uygulama standart bir C++ derleyicisi (örneğin GCC veya Clang) gerektirir.

1.  **Kodu Kaydetme:** Yukarıdaki C++ kodunu `ogr_islemleri.cpp` gibi bir isimle kaydedin.

2.  **Derleme:** Komut satırında (Terminal/CMD) aşağıdaki komutu kullanarak derleyin:
    ```bash
    g++ ogr_islemleri.cpp -o ogrenci_app
    ```

3.  **Çalıştırma:** Uygulamayı çalıştırmak için:
    ```bash
    ./ogrenci_app
    ```

## 🖥️ Kullanım Menüsü

Uygulama başlatıldığında, size aşağıdaki seçenekleri sunan ana menü karşılar:

| Seçenek | İşlem |
| :---: | :--- |
| **1** | Öğrenci İşlemleri (Ekle/Sil)  |
| **2** | Tüm öğrencileri listele  |
| **3** | Belirli bir numaraya göre öğrenci ara  |
| **4** | En yüksek ortalamalı öğrenciyi bul  |
| **5** | Ortalaması 3.0'ın altında olan öğrencileri göster  |
| **6** | Öğrencileri ortalamalarına göre sırala  |
| **7** | Verileri dosyaya kaydet (`ogrenciler.txt`)  |
| **8** | Çıkış  |

## 👨‍💻 Başlangıç Verileri

Uygulama, başlangıçta aşağıdaki 5 öğrenci kaydı ile yüklenir:

| Ad Soyad | Numara | Ortalama (4'lük sistem) |
| :--- | :---: | :---: |
| Mehmet Yılmaz | 205 | 3.02 |
| Rıdvan Çakır | 206 | 2.12 |
| Ayşe Demir | 207 | 3.35 |
| Mert Kılıç | 208 | 2.92 |
| Zeynep Aydın | 209 | 1.45 |

## 🌟 Katkıda Bulunma

Eğer bu projeyi daha da geliştirmek isterseniz (örneğin, daha gelişmiş arama, farklı sıralama algoritmaları veya dosya okuma özelliği eklemek), katkılarınızı memnuniyetle beklerim! Lütfen bir Pull Request (Çekme İsteği) göndermekten çekinmeyin.

---
*Proje: Eren Balkış* 
