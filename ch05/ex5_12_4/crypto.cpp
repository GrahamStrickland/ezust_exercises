// This is the implementation of the ADT Crypto.
// The interface is in the file "crypto.h"

#include "crypto.h"

#include <QTextStream>

QTextStream cerr(stderr);

Crypto::Crypto(ushort key, QString opseq, ushort charsiz) : 
    m_Key(key), m_OpSequence(opseq), m_CharSetSize(charsiz)
{
    //Function body deliberately blank.
}

QString Crypto::encrypt(const QString& str)
{
    QString encrypted = str;

    for (int i = 0; i < m_OpSequence.size(); ++i) {
        if (m_OpSequence.data()[i] == 'p')
            encrypted = permute(encrypted, m_Key);
        else if (m_OpSequence.data()[i] == 's')
            encrypted = shift(encrypted, m_Key);
        else
            cerr << "Error: invalid opsequence code!";
    }

    return encrypted;
}

QString Crypto::decrypt(const QString& str)
{
    QString decrypted = str;

    for (int i = m_OpSequence.size() - 1; i >= 0; --i) {
        if (m_OpSequence.data()[i] == 'p')
            decrypted = unpermute(decrypted, m_Key);
        else if (m_OpSequence.data()[i] == 's')
            decrypted = unshift(decrypted, m_Key);
        else
            cerr << "Error: invalid opsequence code!";
    }

    return decrypted;
}

QString Crypto::shift(const QString& text, unsigned key)
{
    QString cryptext;
    QChar ch;

    srand(key);

    for (int i = 0; i < text.size(); ++i) {
        ch = text.data()[i];
        cryptext += QChar(ch.unicode() + limitedRand(0, m_CharSetSize));
    }

    return cryptext;
}

QString Crypto::unshift(const QString& cryptext, unsigned key)
{
    QString text;
    QChar ch;

    srand(key);
    
    for (int i = 0; i < cryptext.size(); ++i) {
        ch = cryptext.data()[i];
        text += QChar(ch.unicode() - limitedRand(0, m_CharSetSize));
    }

    return text;
}

QString Crypto::permute(const QString& text, unsigned key)
{
    QString scrtext;
    int n = text.size() - 1;

    QVector<int> perm = randomPerm(n, key);

    for (int i = 0; i <= n; ++i)
        scrtext += text.data()[perm[i]];

    return scrtext;
}

QString Crypto::unpermute(const QString& scrtext, unsigned key)
{
    QString text = scrtext;
    int n = scrtext.size() - 1;

    QVector<int> perm = randomPerm(n, key);

    for (int i = 0; i <= n; ++i)
        text.replace(perm[i], 1, scrtext.data()[i]);

    return text;
}

int Crypto::limitedRand(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

QVector<int> Crypto::randomPerm(int n, unsigned key)
{
    QVector<int> perm;
    int random;

    srand(key);

    while (perm.size() <= n) {
        random = limitedRand(0, n);
        if (!perm.contains(random))
            perm << random;
    }

    return perm;
}
