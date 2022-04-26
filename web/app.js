function sendRequest(element) {
    var myHeaders = new Headers();
    myHeaders.append("Authorization", auth_token);
    myHeaders.append("Content-Type", "application/x-www-form-urlencoded");

    var data = element.value
    var urlencoded = new URLSearchParams();
    urlencoded.append("args", data);

    var requestOptions = {
        method: 'POST',
        headers: myHeaders,
        body: urlencoded,
        redirect: 'follow'
    };

    fetch("https://api.particle.io/v1/devices/e00fce68f778c54bccb4bfbb/selLight", requestOptions)
        .then(response => response.text())
        .then(result => console.log(result))
        .catch(error => console.log('error', error));
}