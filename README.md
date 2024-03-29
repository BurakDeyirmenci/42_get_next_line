# Get Next Line
Get Next Line projesi, bir dosyadan okunan her bir satırı döndüren bir işlevin oluşturulmasıyla ilgilidir. Bu işlev, dosya tanıtıcısını (file descriptor) kullanarak metin dosyalarından satır satır veri okuyabilir.

**Neden Önemli?:** Bu işlev, programlarınızın dosya işleme yeteneklerini genişletir. Özellikle büyük metin dosyalarıyla çalışırken, tüm dosyayı belleğe yüklemek yerine satır satır okuma ve işleme yapmak daha verimli ve bellek dostudur.

**Projenin İçeriği:**

1. **Zorunlu Kısım:**
    
    - `get_next_line` fonksiyonunun geliştirilmesi
    - Dosya tanıtıcısından okunan her bir satırın döndürülmesi
    - Bellek sızıntılarının olmaması ve hata durumlarının yönetilmesi
    - Makefile dosyasının oluşturulması
2. **Bonus Kısım:**
    
    - Sadece bir statik değişken kullanarak `get_next_line` işlevinin geliştirilmesi
    - Birden fazla dosya tanıtıcısını aynı anda yönetebilme yeteneği

**Nasıl Kullanılır?:** `get_next_line` işlevi, bir dosya tanıtıcısını ve ardından okunan her satırın adresini döndürür. Bu adres bellekteki bir diziye işaret eder, bu da okunan satırın içeriğini tutar. İşlev çağrıldıkça, farklı satırlar döndürülür, sonunda dosya sonuna ulaşılırsa `NULL` döndürülür.

**Sonuç:** Get Next Line projesi, dosya işleme işlevselliğini artırarak C programlama dilinde dosya okuma ve işleme becerilerini geliştirmeyi amaçlar.