# Movie Recommender

Sistema de recomendação simples, ele utiliza a técnica de Content-based Recommendation. A idéia 
principal é conseguir recomendar para um dado usuário novos itens, baseando­se no seu 
histórico perfil de preferências e as caracteristicas dos itens, ou seja, computar as predições 
utilizando a similaridade entre as características dos itens.

Obs.: Esta aplicação utilizar o projeto *rapidjson*, a pasta está inclusa na fonte.

## Compilar e Executar
- Para compilar o programa, basta executar o Makefile ou executar o seguinte comando:
```
g++ recommender.cpp model/Matrix.cpp model/Movie.cpp model/User.cpp 
model/Prediction.cpp model/Rating.cpp algorithm/TFIDFInvertedIndex.cpp 
algorithm/TFIDFInvertedKey.cpp algorithm/TFIDFInvertedValue.cpp 
algorithm/TFIDFDirectIndex.cpp algorithm/TFIDFDirectKey.cpp algorithm/TFIDFDirectValue.cpp 
parser/ParameterParser.cpp ­o recommender
```

- Após ter compilado o sistema, para executar com o *make run*, ou  seguinte comando no terminal:
```
./recommender content.csv ratings.csv targets.csv > result.csv
```

## Input
Para iniciar a execução deve passar como argumento para o programa, dois arquivos no 
formato CSV. Os dois arquivos CSV como entrada devem seguir o seguinte formato: 

- *content.csv*: contendo <itemId, content>, sendo o id do item e o JSON com informação, contéudo daquele dado item; 

- *ratings.csv*: contendo <userId, itemId, rating>, sendo o id do usuario, id do item e a avaliação que o usuário forneceu sobre aquele item;
 
- *targets.csv*: contendo <userId, itemId>, sendo os pares de previsão; 

## Output
Ao final da execução ele deve retornar um arquivo no formato CSV, no qual cada linha 
possui o resultado da predição de cada par definido no arquivo target. A saída tem o seguinte 
formato: *<userid:itemid,prediction>*
 
- *UserId*: ItemId , contendo o par <userId, itemId> separados por dois pontos (:);

- *Prediction*: contendo a classificação prevista para o par alvo; 
