const NEWS_URL = "https://api.hnpwa.com/v0/news/1.json"
const CONTENT_URL = "https://api.hnpwa.com/v0/item/@id.json"
const div = document.createElement("div");
const ajax = new XMLHttpRequest();

const Ajax = (URL) => {
    ajax.open("GET", URL, false);
    ajax.send();
    return (JSON.parse(ajax.response));
}

const renderDiv = (data) => {
    div.innerHTML = data;
}

const refreshSite = () => {
    const respond = Ajax(NEWS_URL);
    renderDiv(`
        <ul>
        ${respond.map(item => {
        return `
                <li>
                    <a href=#${item.id}>${item.title} ${item.comments_count}</a>
                </li>`;
        }).join('\n')}
        </ul>`);
}

window.addEventListener("hashchange", (e) => {
    const id = location.hash.substr(1);
    if (id === "") {
        refreshSite();
        return;
    }
    const respond = Ajax(CONTENT_URL.replace('@id', id));
    renderDiv(`
        <h1>
            ${respond.title}
        </h1>
    `);
});

window.onload = () => {
    document.body.appendChild(div);
    refreshSite();
}